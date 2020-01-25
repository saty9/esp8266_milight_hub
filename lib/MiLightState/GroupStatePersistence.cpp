#include <GroupStatePersistence.h>
#include <fstream>

static const char FILE_PREFIX[] = "group_states/";

void GroupStatePersistence::get(const BulbId &id, GroupState& state) {
  char path[30];
  memset(path, 0, 30);
  buildFilename(id, path);
  std::ifstream f(path, std::ios_base::in);
  if (f.good()){
    state.load(f);
    f.close();
  }
}

void GroupStatePersistence::set(const BulbId &id, const GroupState& state) {
  char path[30];
  memset(path, 0, 30);
  buildFilename(id, path);

  std::fstream f(path, std::ios_base::out);
  state.dump(f);
  f.close();
}

void GroupStatePersistence::clear(const BulbId &id) {
  char path[30];
  buildFilename(id, path);

  std::ifstream f(path, std::ios_base::in);
  if (f.good()){
    f.close();
    std::remove(path);
  } else {
    f.close();
  }
}

char* GroupStatePersistence::buildFilename(const BulbId &id, char *buffer) {
  uint32_t compactId = id.getCompactId();
  return buffer + sprintf(buffer, "%s%x", FILE_PREFIX, compactId);
}
