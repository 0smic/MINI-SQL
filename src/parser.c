#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"



void parser_command(const char *input){
  if (strncmp(input,"CREATE TABLE", 12) == 0){
      create_table(input);
  }else if (strncmp(input,"SELECT", 5) == 0){
      select_func(input);
  }else if (strncmp(input,"INSERT INTO", 11) == 0){
      printf("working");
  }

}
void create_table(const char *input){
  char table_name[100];
  char column[300];
  if (sscanf(input, "CREATE TABLE %s (%[^)])",table_name,column) ==2){
      printf("\n%s  --  %s\n",table_name,column);
  }else {
      printf("Syntax ERROR!!\n");
      printf("CREATE TABLE table_name column\n");
      printf("column: (column_name datatype, ....)\n");
  }
}


void select_func(const char *input){
  char column[100];
  char table_name[100];
  char condition[300];
  if (sscanf(input, "SELECT %s FROM %s WHERE (%[^)])",column,table_name,condition) ==3){
      printf("\n%s  --  %s -- %s\n",column,table_name,condition);
  }else {
      printf("Syntax ERROR!!\n");
      printf("SELECT column FROM table_name WHERE condition \n");
      printf("condition: (......)\n");
  }
}
