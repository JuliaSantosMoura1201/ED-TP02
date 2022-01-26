#ifndef ENTITY
#define ENTITY

typedef struct  Entity
{
    char *url;
    int amount;
    struct Entity *next;
    int position;
} entity;

void addEntity(char *url, int amount, entity *head, int size);
void printEntities(entity *head);

#endif