#include "my.h"

int my_strcmp(char *a, char *b){
    if(a== NULL && b!=NULL)
        return -1;
    if(b== NULL && a!=NULL)
        return 1;
    if(a == NULL && b == NULL)
        return 0;
    for(;*a == *b;a++,b++){
        if(*a == '\0' && *b == '\0')
            return 0;

    }
    return (*a < *b) ? -1 : 1;
}


