#ifndef ENTITY
#define ENTITY

#include<stdbool.h>

typedef struct  Entity
{
    char *url;
    int amount;
    int tapeIdentifier;
    struct Entity *next;
} entity;

void addEntity(char *url, int amount, int tapeIdentifier, entity *head);
void printEntities(entity *head);
entity *getAtPosition(int position, entity *head);
int getSize(entity *head);
bool isEmpty(entity *head);
#endif