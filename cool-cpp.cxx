#include <iostream>
#include <fstream>
#include <memory>
// #include "Poco/MD5Engine.h"
// #include "Poco/DigestStream.h"
#include "sensor.pb.h"
#include <google/protobuf/util/json_util.h>
#include "out/httplib.h"

Foo build_foo() {
  auto foo = Foo();
  foo.set_bar("Hello world");
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

int main(int argc, char* argv[]) {
  // std::cout << "begin app" << dt.foo << std::endl;
  // std::cout << "Foo default instance " << &_Foo_default_instance_ << std::endl;
  // Poco::MD5Engine md5;
  // Poco::DigestOutputStream ds(md5);
  // ds << "abcdefghijklmnopqrstuvwxyz";
  // ds.close();
  // std::cout << Poco::DigestEngine::digestToHex(md5.digest()) << std::endl;

  // auto sensor = build_sensor();
  // std::ofstream ofs("sensor.data", std::ios_base::out | std::ios_base::binary);
  // sensor.SerializeToOstream(&ofs);
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
  auto host = "localhost";
  auto port = 8080;
  if (argc == 1) {
    httplib::Server svr;

    svr.Get("/foo", [](const httplib::Request &req, httplib::Response &res) {
      Foo foo = build_foo();
      std::string str;
      google::protobuf::util::MessageToJsonString(foo, &str);
      res.set_content(str, "application/json");
    });
    std::cout << "Server mode: listening at port " << port << std::endl;
    svr.listen(host, port);
    return 0;
  }
  httplib::Client cli(host, port);
  auto res = cli.Get("/foo");
  if (res && res->status == 200) {
    Foo out;
    google::protobuf::util::JsonStringToMessage(res->body, &out);
    std::cout << out.bar() << std::endl;
  }
  return 0;
}