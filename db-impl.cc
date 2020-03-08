#include <sstream>
#include "db-impl.h"

DbImpl::DbImpl() {
  sqlite3_open("deleteme.db", &db);
  sqlite3_update_hook(db, [](auto self, auto opration, auto _, auto table, auto id) {
    std::cout << "updated:" << table << ":" << id << std::endl;
  }, this);
  setup();
}

DbImpl::~DbImpl() {
  sqlite3_close(db);
}

void DbImpl::setup() {
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

std::optional<History> DbImpl::getLastHistory() {
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

std::list<Entity> DbImpl::getEntities() {
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

int DbImpl::addEntity(Entity &entity) {
  char *err;
  std::stringstream ss;
  ss << "insert into entity(name, age) values('" << entity.name << "', " << entity.age <<");";
  sqlite3_exec(db, ss.str().c_str(), 0, 0, &err);
  return sqlite3_last_insert_rowid(db);
}
