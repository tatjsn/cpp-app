#include <iostream>
#include <fstream>
#include <memory>
// #include "Poco/MD5Engine.h"
// #include "Poco/DigestStream.h"
#include "sensor.pb.h"
#include <google/protobuf/util/json_util.h>

class Data {
  public:
    int foo;
    int bar;
}

class Hoge {
  public:
    Hoge();
    ~Hoge();
};

Hoge::Hoge() {
  std::cout << "Hoge created " << this << std::endl;
}

Hoge::~Hoge() {
  std::cout << "Hoge destructed " << this << std::endl;
}

Foo build_foo() {
  auto foo = Foo();
  foo.set_bar("Default Bar");
  return foo;
}

void decorate_foo(Foo &foo) {
  foo.set_bar("Boom");
}

Sensor build_sensor() {
  // auto foo = build_foo();
  auto fooPtr = new Foo();
  Foo &foo = *fooPtr;
  decorate_foo(foo);
  auto sensor = Sensor();
  sensor.set_name("CoolName");
  sensor.set_humidity(50);
  sensor.set_temperature(35.6);
  sensor.set_door(Sensor::SwitchLevel::Sensor_SwitchLevel_OPEN);
  // (*sensor.mutable_foo()) = std::move(foo); // not performant
  sensor.set_allocated_foo(fooPtr);
  return sensor;
}

int main() {
  Data dt{1, 2};
  dt.bar = 100;
  std::cout << "begin app" << dt.foo << std::endl;
  std::cout << "Foo default instance " << &_Foo_default_instance_ << std::endl;
  // Poco::MD5Engine md5;
  // Poco::DigestOutputStream ds(md5);
  // ds << "abcdefghijklmnopqrstuvwxyz";
  // ds.close();
  // std::cout << Poco::DigestEngine::digestToHex(md5.digest()) << std::endl;

  auto sensor = build_sensor();
  std::ofstream ofs("sensor.data", std::ios_base::out | std::ios_base::binary);
  sensor.SerializeToOstream(&ofs);
  // sensor.release_foo();
  // ofs.flush();

  // std::ifstream ifs("sensor.data", std::ios_base::in | std::ios_base::binary);
  // Sensor sensor2;
  // sensor2.ParseFromIstream(&ifs);

  // std::string str;
  // google::protobuf::util::MessageToJsonString(sensor2, &str);
  // std::cout << str << std::endl;
  // // google::protobuf::ShutdownProtobufLibrary();
  // std::cout << "After shutdown" << std::endl;
}