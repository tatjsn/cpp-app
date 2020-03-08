#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include "out/foo.pb.h"
#include "out/foo-dto.pb.h"
#include "out/httplib.h"
#include "db-impl.h"

void map_entity_to_foo(const Entity &entity, Foo *fooPtr) {
  fooPtr->set_id(entity.id);
  fooPtr->set_bar(entity.name);
  fooPtr->set_baz(entity.age);
}

Entity map_foo_to_entity(const Foo &foo) {
  return Entity {foo.id(), foo.bar(), foo.baz()};
}

int main(int argc, char* argv[]) {
  auto host = "localhost";
  auto port = 8080;
  if (argc == 1) {
    DbImpl dbImpl;
    Db &db = dbImpl;
    httplib::Server svr;

    svr.Get("/foo", [&](auto &req, auto &res) {
      auto entities = db.getEntities();
      FooDto dto;
      for (auto entity : entities) {
        auto fooPtr = dto.add_foos();
        map_entity_to_foo(entity, fooPtr);
      }
      res.set_content(dto.SerializeAsString(), "application/protobuf");
    });

    svr.Post("/foo", [&](auto &req, auto &res, auto &content_reader) {
      std::string body;
      content_reader([&](const char *data, size_t data_length) {
        body.append(data, data_length);
        return true;
      });
      FooDto dto;
      dto.ParseFromString(body);
      std::list<int> ids;

      for (auto foo : dto.foos()) {
        auto entity = map_foo_to_entity(foo);
        auto id = db.addEntity(entity);
        ids.push_back(id);
      }
      std::stringstream ss;
      for (auto id: ids) {
        ss << "," << id;
      }
      res.set_content(&ss.str().c_str()[1], "text/plain");
    });
    std::cout << "Server mode: listening at port " << port << std::endl;
    svr.listen(host, port);
    return 0;
  }

  httplib::Client cli(host, port);
  std::string get = "get";
  std::string post = "post";
  std::string dump = "dump";

  if (argc == 2 && get.compare(argv[1]) == 0) {
    auto res = cli.Get("/foo");
    if (res && res->status == 200) {
      FooDto dto;
      dto.ParseFromString(res->body);
      std::cout << dto.DebugString() << std::endl;
    }
    return 0;
  }

  if (argc > 3 && post.compare(argv[1]) == 0) {
    Entity entity {0, argv[2], std::atoi(argv[3])};
    FooDto dto;
    auto fooPtr = dto.add_foos();
    map_entity_to_foo(entity, fooPtr);
    auto res = cli.Post("/foo", dto.SerializeAsString(), "application/protobuf");
    if (res && res->status == 200) {
      std::cout << res->body << std::endl;
    }
    return 0;
  }

  if (argc == 2 && dump.compare(argv[1]) == 0) {
    DbImpl dbImpl;
    Db &db = dbImpl;
    auto entities = db.getEntities();
    for (auto entity : entities) {
      std::cout << entity.id << "|" << entity.name << "|" << entity.age << std::endl;
    }
    return 0;
  }

  std::cout << "Unknown command" << std::endl;
  return 1;
}
