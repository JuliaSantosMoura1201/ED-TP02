#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "files.h"
#include "entity.h"
#include "quicksort.h"

void getParameters(char *result, entity *head){

    char *url = strtok(result, " ");
    int amount = atof(strtok(NULL, " "));
    addEntity(url, amount, head);
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

void readFile(FILE *file, int numEntities, int numTapes){
    char line[100];
    char *result;
    while(!feof(file)){
        for(int i = 0; i < numTapes; i++){
            
            entity *head = malloc(sizeof(entity));
            head->next = NULL;

            for(int j = 0; j < numEntities; j ++){
                result = fgets(line, 100, file);
                if(result){
                    getParameters(result, head);
                }
            }
            printEntities(head);
            quickSort(head, numEntities);

            printf("\nAfter Quickstort\n");
            printEntities(head);
            printf("\n\n");
        }
    }
}