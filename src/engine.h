#ifndef ENGINE_H
#define ENGINE_H
  #include "datatype.h"
  typedef struct table table_t;
  union Data;
  int hash(const char *key);
  void create_table(const char *table_name, const char *columns);
#endif // ENGINE_H
