#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "entity.h" 

void printEntities(entity *head){
    entity *aux = head->next;
    while(aux != NULL){
        printf("%s %d\n", aux->url, aux->amount);
        aux = aux->next;
    }
}

entity *createEntity(char *url, int amount, int tapeIdentifier){
    entity *newEntity = malloc(sizeof(entity));
    newEntity->url = strdup(url);
    newEntity->amount = amount;
    newEntity->tapeIdentifier = tapeIdentifier;
    newEntity->next = NULL;
    return newEntity;
}

void addEntity(char *url, int amount, int tapeIdentifier, entity *head){
    entity *newEntity = createEntity(url, amount, tapeIdentifier);
    entity *second = head->next;
    head->next = newEntity;
    newEntity->next = second;
}

entity *getAtPosition(int position, entity *head){
    entity *aux = head->next;
    for(int i = 0; i < position; i++){
       aux = aux->next;
    }
    return aux;
}

int getSize(entity *head){
    int size = 0;
    entity *aux = head->next;
    while(aux != NULL){
        size++;
        aux = aux->next;
    }
    return size;
}

bool isEmpty(entity *head){
    return head->next == NULL;
}