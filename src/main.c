#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

#define INPUT_BUFFER 1024
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


  
}

