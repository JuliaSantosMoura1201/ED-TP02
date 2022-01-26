#ifndef ENTITY
#define ENTITY

typedef struct  Entity
{
    char *url;
    int amount;
    struct Entity *next;
} entity;

void addEntity(char *url, int amount, entity *head);
void printEntities(entity *head);

#endif