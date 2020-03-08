#include <iostream>
#include <list>
#include <optional>
#include <sqlite3.h>

struct Entity {
  int id;
  std::string name;
  int age;
};

struct History {
  int id;
  int version;
};

class Db {
  public:
    virtual std::list<Entity> getEntities() = 0;
    virtual int addEntity(Entity &entity) = 0;
};
