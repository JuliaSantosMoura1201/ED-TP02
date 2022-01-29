#ifndef FILES
#define FILES

#include <stdlib.h>
#include <stdio.h>
#include "entity.h"

FILE *openFile(char *fileName, const char *op);
void readFile(FILE *file, int numEntities, int numTapes);
void readFirstLineFromEach(int numTapes, FILE **files, entity *head);
void writeEntityOnFile(entity *e, FILE *file);
char *nextLineFromFile(int tapeIdentifier, FILE **files);
void getParameters(char *result, int tapeIdentifier, entity *head);
#endif