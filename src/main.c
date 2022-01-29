#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "files.h"
#include "entity.h"
#include "quicksort.h"
#include "heap.h"

int main()
{
    /*int numEntities;
    scanf("%d", &numEntities);

    int numTapes;
    scanf("%d", &numTapes);

    char readFileName[100];
    scanf("%s", readFileName);

    char writeFileName[100];
    scanf("%s", writeFileName);*/

    setbuf(stdout, NULL);
    
    FILE *readingFile = openFile("teste.txt", "rt");
    readFile(readingFile, 5, 7);


    entity *head = malloc(sizeof(entity));
    head->next = NULL;

    FILE *files[7];

    readFirstLineFromEach(7, files, head);

    build(head, 7);

    FILE *exitFile = openFile("exit.txt", "wt");

    while(!isHeapEmpty(head)){
        printf("Entrou no while\n");
        printEntities(head);
        entity *biggestEntity = extractMax(head);
        printf("Depois do extract\n");
        printEntities(head);
        printf("Biggest entity amount: %d\n", biggestEntity->amount);
        writeEntityOnFile(biggestEntity, exitFile);
        printf("wrote entity on file: %s %d \n", biggestEntity->url, biggestEntity->amount);
        char *result = nextLineFromFile(biggestEntity->tapeIdentifier, files);
        printf("next line from file: %s\n", result);
        if(result)
            addOnHeap(result, biggestEntity->tapeIdentifier, head);
    }

    for (int i = 0; i < 7; i++){
        fclose(files[i]);
    }
    
    fclose(exitFile);

    return 0;
}