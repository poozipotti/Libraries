#include "my.h"

char *my_strcpy(char *dst, char *src){
    int i;
    if(src == NULL || dst == NULL){
        dst = NULL;
        return dst;
    }
    for(i=0;src[i] != '\0';i++){
        dst[i] = src[i];
    }
    dst[my_strlen(src)] = '\0';
    return dst;
}
