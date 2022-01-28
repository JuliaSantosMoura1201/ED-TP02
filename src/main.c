#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "files.h"
#include "entity.h"
#include "quicksort.h"

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
    readFirstLineFromEach(7);
    return 0;
}