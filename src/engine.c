#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "engine.h"




typedef enum {
    MYSQL_TYPE_DECIMAL,     // Deprecated
    MYSQL_TYPE_TINY,        // TINYINT
    MYSQL_TYPE_SHORT,       // SMALLINT
    MYSQL_TYPE_LONG,        // INT or INTEGER
    MYSQL_TYPE_FLOAT,       // FLOAT
    MYSQL_TYPE_DOUBLE,      // DOUBLE or REAL
    MYSQL_TYPE_NULL,        // NULL-type column
    MYSQL_TYPE_TIMESTAMP,   // TIMESTAMP
    MYSQL_TYPE_LONGLONG,    // BIGINT
    MYSQL_TYPE_INT24,       // MEDIUMINT
    MYSQL_TYPE_DATE,        // DATE
    MYSQL_TYPE_TIME,        // TIME
    MYSQL_TYPE_DATETIME,    // DATETIME
    MYSQL_TYPE_YEAR,        // YEAR
    MYSQL_TYPE_NEWDATE,     // Newer DATE variant (internal)
    MYSQL_TYPE_VARCHAR,     // VARCHAR
    MYSQL_TYPE_BIT,         // BIT
    MYSQL_TYPE_JSON,        // JSON (MySQL 5.7+)
    MYSQL_TYPE_NEWDECIMAL,  // Precise DECIMAL
    MYSQL_TYPE_ENUM,        // ENUM
    MYSQL_TYPE_SET,         // SET
    MYSQL_TYPE_TINY_BLOB,   // TINYBLOB
    MYSQL_TYPE_MEDIUM_BLOB, // MEDIUMBLOB
    MYSQL_TYPE_LONG_BLOB,   // LONGBLOB
    MYSQL_TYPE_BLOB,        // BLOB
    MYSQL_TYPE_VAR_STRING,  // VARCHAR (old-style)
    MYSQL_TYPE_STRING,      // CHAR, BINARY
    MYSQL_TYPE_GEOMETRY     // Spatial data
} DataType;

typedef struct {
  char *name;
  DataType type;

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


table_t *create_table(const char *table_name, const char *columns_input){
    printf("CREATE TABLE %s (%s)\n", table_name, columns_input);
   char *columns = strdup(columns_input);
   char **column_name, **column_datatype;
    table_t *new_table = malloc(sizeof(table_t));
    if (new_table == NULL) return NULL;

   // Initialize the table structure
    new_table->name = strdup(table_name);
    new_table->column_count = 0;
    new_table->row_capacity = MAX_ROWS;
    new_table->rows_count = 0;

    new_table->column_count = sep_column_datatype(&column_name, &column_datatype, columns);
    printf("column count: %d\n",new_table->column_count);
    for (int i = 0; i < new_table->column_count; i++){
      new_table->column[i]->name = strdup(column_name[i]);
      new_table->column[i]->type = strdup(column_datatype[i]);
    }

}
