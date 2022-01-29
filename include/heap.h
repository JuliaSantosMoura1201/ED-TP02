#ifndef HEAP
#define HEAP

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "entity.h"

void build(entity *head, int n);
void addOnHeap(char *result, int tapeIdentifier, entity *head);
entity *extractMax(entity *head);
bool isHeapEmpty(entity *head);

#endif