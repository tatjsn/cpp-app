#include <iostream>
#include <fstream>
#include <memory>
#include <sqlite3.h>
// #include <google/protobuf/util/json_util.h>
#include "out/foo.pb.h"
#include "out/foo-dto.pb.h"
#include "out/httplib.h"

struct Entity {
  int id;
  std::string name;
  int age;
};

void map_entity_to_foo(const Entity &entity, Foo *fooPtr) {
  fooPtr->set_id(entity.id);
  fooPtr->set_bar(entity.name);
  fooPtr->set_baz(entity.age);
}

Entity map_foo_to_entity(Foo foo) {
  return Entity {foo.id(), foo.bar(), foo.baz()};
}

struct History {
  int id;
  int version;
};

class Db {
  private:
    sqlite3 *db;
    void setup();

  public:
    Db();
    ~Db();
    std::optional<History> getLastHistory();
    std::list<Entity> getEntities();
};

Db::Db() {
  sqlite3_open("deleteme.db", &db);
  setup();
}

Db::~Db() {
  sqlite3_close(db);
}

void Db::setup() {
  char *err;
  sqlite3_exec(db, "create table if not exists history(id integer primary key autoincrement, version integer);", 0, 0, &err);
  auto lastHistory = getLastHistory().value_or(History {0, 0});
  std::cout << "db version: " << lastHistory.version << std::endl;
  if (lastHistory.version < 1) {
    sqlite3_exec(db, "create table entity(id integer primary key autoincrement, name text, age integer);", 0, 0, &err);
    sqlite3_exec(db, "insert into history(version) values(1);", 0, 0, &err);
  }
  if (lastHistory.version < 2) {
    sqlite3_exec(db, "insert into entity(name, age) values('Jack', 10);", 0, 0, &err);
    sqlite3_exec(db, "insert into entity(name, age) values('Jill', 11);", 0, 0, &err);
    sqlite3_exec(db, "insert into history(version) values(2);", 0, 0, &err);
  }
}

std::optional<History> Db::getLastHistory() {
  sqlite3_stmt *stmt;
  std::optional<History> history;
  sqlite3_prepare_v2(db, "select * from history order by id desc limit 1;", -1, &stmt, 0);
  while (sqlite3_step(stmt) == SQLITE_ROW) {
    history.emplace(History {
      sqlite3_column_int(stmt, 0),
      sqlite3_column_int(stmt, 1)
    });
  }
  sqlite3_finalize(stmt);
  return history;
}

std::list<Entity> Db::getEntities() {
  sqlite3_stmt *stmt;
  std::list<Entity> entities;
  sqlite3_prepare_v2(db, "select * from entity;", -1, &stmt, 0);
  while (sqlite3_step(stmt) == SQLITE_ROW) {
    entities.push_back(Entity {
      sqlite3_column_int(stmt, 0),
      (char*)sqlite3_column_text(stmt, 1),
      sqlite3_column_int(stmt, 2)
    });
  }
  sqlite3_finalize(stmt);
  return entities;
}


// int main() {
//   Db db;
//   auto entities = db.getEntities();
//   for (auto entity : entities) {
//     std::cout << entity.id << entity.name << entity.age << std::endl;
//   }
//   return 0;
// }

int main(int argc, char* argv[]) {
  auto host = "localhost";
  auto port = 8080;
  if (argc == 1) {
    Db db;
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
    std::cout << "Server mode: listening at port " << port << std::endl;
    svr.listen(host, port);
    return 0;
  }

  httplib::Client cli(host, port);
  auto res = cli.Get("/foo");
  if (res && res->status == 200) {
    FooDto dto;
    dto.ParseFromString(res->body);
    std::cout << dto.DebugString() << std::endl;
  }
  return 0;
}
