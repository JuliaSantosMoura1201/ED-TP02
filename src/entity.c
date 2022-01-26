#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "entity.h" 

void printEntities(entity *head){
    entity *aux = head->next;
    while(aux != NULL){
        printf("%s %d\n", aux->url, aux->amount);
        aux = aux->next;
    }
}

entity *createEntity(char *url, int amount){
    entity *newEntity = malloc(sizeof(entity));
    newEntity->url = strdup(url);
    newEntity->amount = amount;
    newEntity->next = NULL;
    return newEntity;
}

void addEntity(char *url, int amount, entity *head){
    entity *newEntity = createEntity(url, amount);
    entity *second = head->next;
    head->next = newEntity;
    newEntity->next = second;
}

