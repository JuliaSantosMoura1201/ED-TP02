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

char *createWriteFileName(int tapeIndex){
    char *fileName = malloc (sizeof (char) * 25);
    sprintf(fileName, "rodada-%i.txt", tapeIndex);
    return fileName;
}

void writeOnFile(char *line, FILE *file){
    char *str = malloc(strlen(line));
    strcpy(str, line);
    fputs(str, file);
    fputs("\n", file);
}


void writeEntitiesAtFile(entity *head, FILE *file){
    entity *aux = head->next;
    while(aux != NULL){
        char *line = malloc (sizeof (char) * 25);
        sprintf(line, "%s %d", aux->url, aux->amount);
        writeOnFile(line, file);
        aux = aux->next;
    }
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
            
            quickSort(head, numEntities);

            FILE *file = openFile(createWriteFileName(i), "wt");
            writeEntitiesAtFile(head, file);
        }
    }
}