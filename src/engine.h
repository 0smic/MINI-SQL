#ifndef ENGINE_H
#define ENGINE_H
  #include <stdbool.h>
  #include "datatype.h"
  #define MAX_COLUMNS 10
  #define MAX_ROWS 100
  #define HASHTABLE_TABLE_SIZE 100
  typedef struct table table_t;
  union Data;
  int hash(const char *key);
  void create_table(const char *table_name, const char *columns);
  bool is_table_exist(const char *table_name);
  void insert_row_into_table(char *table_name,char *columns, char *values);
  void *check(int data_type, char *value);
#endif // ENGINE_H
