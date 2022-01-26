#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "files.h"
#include "entity.h"
#include "quicksort.h"

int main()
{
   /* int numEntidades;
    scanf("%d", &numEntidades);

    char readFileName[100];
    scanf("%s", readFileName);*/

    setbuf(stdout, NULL);
    entity *head = malloc(sizeof(entity));
    head->next = NULL;
    
    FILE *readingFile = openFile("teste.txt", "rt");
    readFile(readingFile, head);

    printEntities(head);
    quickSort(head, 5);

    printf("\n\nAfter Quickstort\n");
    printEntities(head);
    return 0;
}