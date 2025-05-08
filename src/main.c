#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_BUFFER 1024
void parser_command(const char *input);
void create_table(const char *input);
void cl_loop();

int main(){
    cl_loop();
    
}

void cl_loop(){
    char input[INPUT_BUFFER];
    while(1){
        printf("Mysql> ");
        if(!fgets(input,INPUT_BUFFER,stdin)) break;
        input[strcspn(input, "\n")] = '\0';
        
        if (strcmp(input,"exit") == 0 || strcmp(input,"quit") == 0){
            printf("THE END");
            break;
        }
        parser_command(input);
    }
    
}

void parser_command(const char *input){
    if (strncmp(input,"CREATE TABLE", 12) == 0){
        create_table(input);
    }else if (strncmp(input,"SELECT", 5) == 0){
        printf("working");
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

