#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "parser.h"
#include "engine.h"



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

int table_count = 0;


typedef struct {
  char *name;
  DataType type;
  union Data data;

} column_t;


typedef struct {
  void** rows_data;
} row_t;

typedef struct table{
  char *name;
  column_t *column[MAX_COLUMNS];
  int column_count;

  int row_capacity;
  int rows_count;
  row_t *rows[MAX_ROWS];
}table_t;

table_t *hashtable[HASHTABLE_TABLE_SIZE];

table_t *table_list[50];


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
    table_list[table_count++] = new_table;
    index = hash(new_table->name);
    hashtable[index] = new_table;
}

void *check(int data_type, char *value){
    void *addr = NULL;
    if(data_type == 1){
        addr = malloc(sizeof(int));
        if(addr) *(int *)addr = atoi(value);
    }else if (data_type == 2){
        addr = strdup(value);
    }
    return addr;

void insert_row_into_table(char *table_name,char *columns, char *values){
    char *column_name[10],*column_values[10];
    int count = sep_column_values(columns,values,column_name,column_values);
    void **row = malloc(sizeof(void) * count);
    printf("after %s ", column_name[0]);
    for(int i =0;i<count;i++){
        row[i] = check(1,column_name[i]);
        printf("values : %d \n",*(int *)row[i]);
    }
}



bool is_table_exist(const char *table_name){
    int index = hash(table_name);
    if (hashtable[index] != NULL && strcmp(hashtable[index]->name,table_name) == 0){
        printf("TABLE EXISTS");
        return true;
    }else{
        printf("TABLE DOES NOT EXIST");
        return false;
    }
}



int hash(const char *key){
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++){
        hash += key[i];
    }
    return hash % HASHTABLE_TABLE_SIZE;
}
