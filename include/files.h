#ifndef FILES
#define FILES

#include <stdlib.h>
#include <stdio.h>
#include "entity.h"

FILE *openFile(char *fileName, const char *op);
void readFile(FILE *file, int numEntities, int numTapes);

#endif