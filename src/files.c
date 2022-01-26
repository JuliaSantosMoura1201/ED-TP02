#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "files.h"
#include "entity.h"

void getParameters(char *result, entity *head, int size){

    char *url = strtok(result, " ");
    int amount = atof(strtok(NULL, " "));
    addEntity(url, amount, head, size);
}

FILE *openFile(char *name, const char *op){
    FILE *file;
    
    file = fopen(name, op);
    
    if(file == NULL){
        printf("Problemas na abertura do arquivo\n");
        exit(1);
    }
    
    return file;
}

void readFile(FILE *file, entity *head, int size){
    char line[100];
    char *result;
    while(!feof(file)){
        result = fgets(line, 100, file);
        if(result){
            getParameters(result, head, size);
        }
    }
}