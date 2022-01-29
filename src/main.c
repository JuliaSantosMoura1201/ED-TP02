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
    readFile(readingFile, 5, 10);

    entity *head = malloc(sizeof(entity));
    head->next = NULL;

    FILE *files[10];

    readFirstLineFromEach(10, files, head);

    build(head, 10);

    FILE *exitFile = openFile("exit.txt", "wt");

    while(!isEmpty(head)){
        entity *biggestEntity = extractMax(head);
        writeEntityOnFile(biggestEntity, exitFile);
        char *result = nextLineFromFile(biggestEntity->tapeIdentifier, files);
        if(result)
            addOnHeap(result, biggestEntity->tapeIdentifier, head);
    }

    for (int i = 0; i < 10; i++){
        fclose(files[i]);
    }
    
    fclose(exitFile);

    return 0;
}