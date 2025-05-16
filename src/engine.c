#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "parser.h"
#include "engine.h"


#define HASHTABLE_TABLE_SIZE 100

union Data{
    int8_t tinyint;           // TINYINT
    int16_t smallint;      // SMALLINT
    int32_t integer;       // INTEGER
    int64_t bigint;        // BIGINT
    float float_value;     // FLOAT
    double double_value;   // DOUBLE
    char *varchar_value;   // VARCHAR
    void *unkonw;          // UNKNOWN
    
};


typedef struct {
  char *name;
  struct table *table;
}tables_t;

tables_t *hashtable[HASHTABLE_TABLE_SIZE]; // creating hashmap to fetch table fastly
typedef struct {
  char *name;
  DataType type;
  union Data data;

} column_t;

typedef struct table{
  char *name;
  column_t *column[MAX_COLUMNS];
  int column_count;

  int row_capacity;
  int rows_count;
}table_t;

typedef struct {
  void** rows;
} row_t;


void create_table(const char *table_name, const char *columns_input){
   int index = 0;
   printf("CREATE TABLE %s (%s)\n", table_name, columns_input);
   char *columns = strdup(columns_input);
   char **column_name, **column_datatype;
    table_t *new_table = malloc(sizeof(table_t));
    if (new_table == NULL){
        printf("Memory allocation failed");
        return;
    }

   // Initialize the table structure
    new_table->name = strdup(table_name);
    new_table->column_count = 0;
    new_table->row_capacity = MAX_ROWS;
    new_table->rows_count = 0;

    new_table->column_count = sep_column_datatype(&column_name, &column_datatype, columns);
    printf("column count: %d\n",new_table->column_count);
    for (int i = 0; i < new_table->column_count; i++){
      new_table->column[i] = malloc(sizeof(column_t));
      new_table->column[i]->name = strdup(column_name[i]);
      new_table->column[i]->type = get_data_type_from_string(column_datatype[i]);
    }

    // storing values and initializing table in hashmap
    index = hash(new_table->name);
    hashtable[index] = malloc(sizeof(tables_t));
}

int hash(const char *key){
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++){
        hash += key[i];
    }
    return hash % HASHTABLE_TABLE_SIZE;
}
