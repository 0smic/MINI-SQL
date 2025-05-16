#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "engine.h"




void parser_command(const char *input){
  if (strncmp(input,"CREATE TABLE", 12) == 0){
      create_parser(input);
  }else if (strncmp(input,"SELECT", 5) == 0){
      select_parser(input);
  }else if (strncmp(input,"INSERT INTO", 11) == 0){
      insert_into_parser(input);
  }else if (strncmp(input,"DELETE FROM", 11) == 0){
      delete_parser(input);
  }else if (strncmp(input,"UPDATE", 6) == 0){
      update_parser(input);
  }else if (strncmp(input,"DROP TABLE", 9) == 0){
      drop_parser(input);
  }else{
      printf("UNKOWN COMMAND\n");
  }

}
void create_parser(const char *input){
  char table_name[100];
  char column[300];
  if (sscanf(input, "CREATE TABLE %s (%[^)])",table_name,column) ==2){
      printf("\n%s  --  %s\n",table_name,column);
      create_table(table_name, column);
  }else {
      printf("Syntax ERROR!!\n");
      printf("CREATE TABLE table_name column\n");
      printf("column: (column_name datatype, ....)\n");
      return;
  }
    
}


void select_parser(const char *input){
  char table_name[100];
  char column[100];
  char condition[300];
  if (sscanf(input, "SELECT %s FROM %s WHERE (%[^)])",column,table_name,condition) ==3){
      printf("\n%s  --  %s -- %s\n",column,table_name,condition);
  }else {
      printf("Syntax ERROR!!\n");
      printf("SELECT column FROM table_name WHERE condition \n");
      printf("condition: (......)\n");
  }
}

void delete_parser(const char *input){
  char table_name[100];
  char condition[300];
  if (sscanf(input, "DELETE FROM %s WHERE (%[^)])",table_name,condition) ==2){
      printf("\n%s  --  %s\n",table_name,condition);
  }else {
      printf("Syntax ERROR!!\n");
      printf("DELETE FROM table_name WHERE (condition)\n");  
  }
}


void insert_into_parser(const char *input){
  char table_name[100];
  char column[300];
  char values[300];
  if (sscanf(input, "INSERT INTO %s (%[^)]) VALUES (%[^)])",table_name,column,values) ==3){
      printf("\n%s  --  %s -- %s\n",table_name,column,values);
  }else {
      printf("Syntax ERROR!!\n");
      printf("INSERT INTO table_name (column,...) VALUES (values,...)\n");  
  }
}

void update_parser(const char *input){
  char table_name[100];
  char keyValue[600];
  char condition[300];
  if (sscanf(input, "UPDATE %s SET (%[^)]) WHERE (%[^)])",table_name,keyValue,condition) ==3){
      printf("\n%s  --  %s -- %s\n",table_name,keyValue,condition);
  }else {
      printf("Syntax ERROR!!\n");
      printf("UPDATE table_name SET (column1 = value1, column2 = value2, ...) WHERE (condition);\n");  
  }
}

void drop_parser(const char *input){
  char table_name[100];
  if (sscanf(input, "DROP TABLE %s",table_name) ==1){
      printf("\n%s\n",table_name);
  }else {
      printf("Syntax ERROR!!\n");
      printf("DROP TABLE table_name\n");  
  }
}



int sep_column_datatype(char ***column_name, char ***column_datatype, char *column){
    /*This function tokenize the column name and the datatype and return it*/
     *column_name = malloc(MAX_COLUMNS * sizeof(char*));
     *column_datatype = malloc(MAX_COLUMNS * sizeof(char*));
     int index = 0;
     int count = 1;
     for(char *p = column;*p;p++){
         if(*p == ','){
             count++;
         }
     }
     char *saveptr1, *saveptr2;
     char *pair = strtok_r(column,",",&saveptr1);
     while(pair != NULL && index < count){
         (*column_name)[index] = strtok_r(pair, " ",&saveptr2);
         (*column_datatype)[index] = strtok_r(NULL, " ",&saveptr2);
         if((*column_name)[index] != NULL && (*column_datatype)[index] != NULL){
             printf("name : %s , datatype: %s\n",(*column_name)[index],(*column_datatype)[index]);
         }
         pair = strtok_r(NULL, ",",&saveptr1);
         index++;
     }
    return count;
}


DataType get_data_type_from_string(const char *type_str) {
    if (strncmp(type_str, "TINYINT", 7) == 0) {
        return MYSQL_TYPE_TINY;
    } else if (strncmp(type_str, "SMALLINT", 8) == 0) {
        return MYSQL_TYPE_SHORT;
    } else if (strncmp(type_str, "INT", 3) == 0 || strncmp(type_str, "INTEGER", 7) == 0) {
        return MYSQL_TYPE_LONG;
    } else if (strncmp(type_str, "FLOAT", 5) == 0) {
        return MYSQL_TYPE_FLOAT;
    } else if (strncmp(type_str, "DOUBLE", 6) == 0 || strncmp(type_str, "REAL", 4) == 0) {
        return MYSQL_TYPE_DOUBLE;
    } else if (strncmp(type_str, "NULL", 4) == 0) {
        return MYSQL_TYPE_NULL;
    } else {
        return -1; // Unknown type
    }
}
