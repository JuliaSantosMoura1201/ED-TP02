#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "entity.h"
#include "files.h"
#include "stringUtil.h"

void rebuild(int left, int right, entity *head){
    int i = left;
    int j = (i+1)*2 - 1;

    entity *x = getAtPosition(i, head);
    char *url = x->url;
    int amount = x->amount;
    int tape = x->tapeIdentifier;
    
    while(j <= right-1){
        if (j < right-1){
           if(getAtPosition(j, head)->amount < getAtPosition(j + 1, head)->amount){
                j++;
           } 
           else if(getAtPosition(j, head)->amount == getAtPosition(j+1, head)->amount){
               if( !urlIcomesFirstInAlphabeticalOrder(getAtPosition(j, head)->url, getAtPosition(j+ 1, head)->url)) {
                   j++;
               }
           } 
        }if(amount > getAtPosition(j, head)->amount) break;
        else if(amount == getAtPosition(j, head)->amount){
            if(urlIcomesFirstInAlphabeticalOrder(url, getAtPosition(j, head)->url)) break;
        }
        
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
}

void build(entity *head, int n){
    int left = (n/2);
    while(left > 0){
        left--;
        rebuild(left, n, head);
    }
}

entity *extractMax(entity *head){
    entity *first = head->next;
    entity *second = first->next;

    head->next = second;

    return first;
}

void addOnHeap(char *result, int tapeIdentifier, entity *head){
    char copy[100];
    char *url = strtok(result, " ");
    char *strAmount = strtok(NULL, " ");
    int amount = atof(strAmount);
    addEntity(url, amount, tapeIdentifier, head);
    int size = getSize(head);
    build(head, size);
}