#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "files.h"
#include "entity.h"
#include "quicksort.h"
#include "heap.h"

void getParameters(char *result, int tapeIdentifier, entity *head){
    char *url = strtok(result, " ");
    int amount = atof(strtok(NULL, " "));
    addEntity(url, amount, tapeIdentifier, head);
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

char *createTapeFileName(int tapeIndex){
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

void writeEntityOnFile(entity *e, FILE *file){
    char *line = malloc (sizeof (char) * 200);
    sprintf(line,"%s %d",e->url, e->amount);
    writeOnFile(line, file);
}

void writeEntitiesOnFile(entity *head, FILE *file){
    entity *aux = head->next;
    while(aux != NULL){
        writeEntityOnFile(aux, file);
        aux = aux->next;
    }
}

void readFile(FILE *file, int numEntities, int numTapes){
    char line[100];
    char *result;
        for(int i = 0; i < numTapes; i++){
            entity *head = malloc(sizeof(entity));
            head->next = NULL;

            for(int j = 0; j < numEntities; j ++){
                result = fgets(line, 100, file);
                if(result){
                    getParameters(result, i, head);
                }
            }
            
            if(!isEmpty(head))
                quickSort(head, getSize(head));
            
            FILE *file = openFile(createTapeFileName(i), "wt");
            writeEntitiesOnFile(head, file);

            fclose(file);
        }
}

void readFirstLineFromEach(
    int numTapes,
    FILE **files,
    entity *head
){
    for(int i = numTapes-1; i >= 0; i--){
        char *fileName = createTapeFileName(i);
        FILE *file = openFile(fileName, "rt");
        files[i] = file;
        char line[100], *result;
        result = fgets(line, 100, file);
        getParameters(result, i, head);
    }
}

char *nextLineFromFile(int tapeIdentifier, FILE **files){
    FILE *selectedFile = files[tapeIdentifier];
    char line[100], *result;
    result = fgets(line, 100, selectedFile);
    return result;
}