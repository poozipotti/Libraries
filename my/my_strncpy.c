#include "my.h"

char *my_strncpy(char *dst, char *src,int n){
    int i;
    if(src == NULL || dst == NULL){
        dst = NULL;
        return dst;
    }
    for(i=0;src[i] != '\0' && i<n;i++){
        dst[i] = src[i];
    }
    if(my_strlen(src) == -1){
        dst[0] = '\0';
    }else{
        dst[i ++] = '\0';
    }
    return dst;
}
