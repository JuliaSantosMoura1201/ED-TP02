#ifndef ENTITY
#define ENTITY

typedef struct  Entity
{
    char *url;
    int amount;
    int tapeIdentifier;
    struct Entity *next;
} entity;

void addEntity(char *url, int amount, int tapeIdentifier, entity *head);
void printEntities(entity *head);

#endif