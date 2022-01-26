#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "entity.h" 

int qtd = 1;

void printEntities(entity *head){
    entity *aux = head->next;
    while(aux != NULL){
        printf("%s %d Index: %d\n", aux->url, aux->amount, aux->position);
        aux = aux->next;
    }
}

entity *createEntity(char *url, int amount, int size){
    entity *newEntity = malloc(sizeof(entity));
    newEntity->url = strdup(url);
    newEntity->amount = amount;
    newEntity->position = size - qtd;
    newEntity->next = NULL;
    return newEntity;
}

void addEntity(char *url, int amount, entity *head, int size){
    entity *newEntity = createEntity(url, amount, size);
    entity *second = head->next;
    head->next = newEntity;
    newEntity->next = second;
    qtd++;
}

