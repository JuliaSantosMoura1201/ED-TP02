#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "stringUtil.h"

char *removeSubString(const char *hostName, const char *substring){
    int hostNameSize = strlen(hostName);
    char *aux = malloc(hostNameSize);
    char startSize = strlen(substring);
    return strncpy(aux, hostName+startSize, hostNameSize - startSize);
}

bool urlIcomesFirstInAlphabeticalOrder(char *oldUrlI, char *oldUrlJ){
    char *urlI = removeSubString(oldUrlI, "http://");
    char *urlJ = removeSubString(oldUrlJ, "http://");
    bool urlISmaller = false;
    int urlISize = strlen(urlI);
    int urlJSize = strlen(urlJ);
    int smallerStringSize = urlJSize;

    if(urlISize <= urlJSize) smallerStringSize = urlISize;

    
    int i = 0;
    while(i < smallerStringSize){
        if(urlI[i] < urlJ[i]){
            urlISmaller = true;
            break;
        }else if(urlI[i] > urlJ[i]){
            break;
        }else{
            i++;
        }
    }


    return urlISmaller;
}