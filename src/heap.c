#include <stdlib.h>
#include <stdio.h>
#include "entity.h"

void rebuild(int left, int right, entity *head){
    int i = left;
    int j = (i+1)*2 - 1;

    entity *x = getAtPosition(i, head);
    char *url = x->url;
    int amount = x->amount;
    int tape = x->tapeIdentifier;
    
    while(j <= right-1){
        if (j < right-1)
           if(getAtPosition(j, head)->amount < getAtPosition(j + 1, head)->amount) j++;
        
        if(amount >= getAtPosition(j, head)->amount) break;
        
        // A[i] = A[j]
        entity *entityJ = getAtPosition(j, head);
        entity *entityI = getAtPosition(i, head);

        entityI->url = entityJ->url;
        entityI->amount = entityJ->amount;
        entityI->tapeIdentifier = entityJ->tapeIdentifier;
        
        i = j;
        j = (i+1)*2 - 1;
    }
    entity *entityI = getAtPosition(i, head);
    
    entityI->url = url;
    entityI->amount = amount;
    entityI->tapeIdentifier = tape;

    printEntities(head);
        
}

void build(entity *head, int n){
    int left = (n/2);
    while(left > 0){
        left--;
        rebuild(left, n, head);
    }
}