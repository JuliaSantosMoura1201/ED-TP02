#include <stdlib.h>
#include <stdio.h>

#include "entity.h"

entity *findPivot(int *i, int *j, entity *head){
    int correctPosition = (*i + *j)/2;
    return getAtPosition(correctPosition, head);
}

void changePositions(int *i, int*j, entity *head){
    
    entity *previousI = head;
    if(*i != 0) previousI = getAtPosition( *i - 1, head);
    entity *entityI = previousI->next;

    entity *previousJ = head;
    if(*j != 0)previousJ = getAtPosition(*j - 1, head);
    entity *entityJ = previousJ->next;
    entity *nextJ = entityJ->next;

    if((*i) == (*j) - 1){
        previousI->next = entityJ;
        entityJ->next = entityI;
        entityI->next = nextJ;
    }else{
        // A[*i] = A[*j]
        previousI->next = entityJ;
        entityJ->next = entityI->next;

        //A[*j] = A[*i]
        previousJ->next = entityI;
        entityI->next = nextJ;
    }
}

void partition(
    int left,
    int right,
    int *i,
    int *j,
    entity *head
){
    *i = left;
    *j = right;
    entity *_pivot = findPivot(i, j, head);
    do{
        while(_pivot->amount < getAtPosition(*i, head)->amount)(*i)++;
        while(_pivot->amount > getAtPosition(*j, head)->amount)(*j)--;

        if(*i <= *j){
            changePositions(i, j, head);
            (*i)++;
            (*j)--;
        } 
    }while( *i <= *j);
}


void sort(
    int left,
    int right,
    entity *head
){
    int i, j;
    partition(left, right, &i, &j, head);
    if(left < j) sort(left, j, head);
    if(i < right) sort(i, right, head);
}

void quickSort(entity *head, int n){
    sort(0, n-1, head);
}