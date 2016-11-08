#include "my.h"
int my_strncmp(char *a, char *b, int n){
    if(n<0){
        n=0;
    }
    if(n==0){
        return 0;
    }
    if(a== NULL && b !=NULL)
        return -1;
    if(b== NULL && a !=NULL)
        return 1;
    if(a == NULL && b == NULL)
        return 0;
    for(;*a == *b && n > 1;a++, b++, n--){
        if(*a == '\0' && *b == '\0')
            return 0;

    }
    if(*a == *b){
        return 0;
    }
    return (*a < *b) ? -1 : 1;
}


