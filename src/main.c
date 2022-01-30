#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "files.h"
#include "entity.h"
#include "quicksort.h"
#include "heap.h"

int main()
{
    int numEntities;
    printf("Insira o número de entidades por rodada:");
    scanf("%d", &numEntities);

    int numTapes;
    printf("Insira o número de rodadas:");
    scanf("%d", &numTapes);

    char readFileName[100];
    printf("Insira o nome do arquivo de entrada:");
    scanf("%s", readFileName);

    char writeFileName[100];
    printf("Insira o nome do arquivo de saída:");
    scanf("%s", writeFileName);

    setbuf(stdout, NULL);
    
    FILE *readingFile = openFile(readFileName, "rt");
    readFile(readingFile, numEntities, numTapes);

    entity *head = malloc(sizeof(entity));
    head->next = NULL;

    FILE *files[numTapes];

    readFirstLineFromEach(numTapes, files, head);

    build(head, numTapes);

    FILE *exitFile = openFile(writeFileName, "wt");

    while(!isEmpty(head)){
        printf("\n");
        printEntities(head);
        entity *biggestEntity = extractMax(head);
        printf("\nPrint max value: %s %d\n", biggestEntity->url, biggestEntity->amount);
        writeEntityOnFile(biggestEntity, exitFile);
        char *result = nextLineFromFile(biggestEntity->tapeIdentifier, files);
        if(result)
            addOnHeap(result, biggestEntity->tapeIdentifier, head);
        else{
            int size = getSize(head);
            build(head, size);
        }
    }

    for (int i = 0; i < numTapes; i++){
        fclose(files[i]);
    }
    
    fclose(exitFile);

    return 0;
}