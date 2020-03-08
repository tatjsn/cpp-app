#include "db.h"

class DbImpl: public Db {
  private:
    sqlite3 *db;
    void setup();
    std::optional<History> getLastHistory();
  public:
    DbImpl();
    ~DbImpl();
    std::list<Entity> getEntities();
    int addEntity(Entity &entity);
};
