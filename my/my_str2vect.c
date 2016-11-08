#include "my.h"

char **my_str2vect(char * x){
    int strings = 0;
    int i,j,k;
    int stringAdded = 0;
    char ** output;
    if(x == NULL){
        return NULL;
    }
    for(i =0; (x[i] != '\0'); i++){
        if(x[i] >= '!' && x[i] <= '~'){
            if(!stringAdded){
                strings ++;
            stringAdded = 1;}
        }else{
            stringAdded = 0;
        }
    }
    output = (char**)malloc((sizeof(char *)) * strings + 1 );
    stringAdded = 0;
    k = strings;
    for(i =0; (x[i] != '\0'); i++){
        if(x[i] >= '!' && x[i] <= '~'){
            if(!stringAdded){
                j=i;
                stringAdded= 1;
            }
        }else{
            if(stringAdded){
                stringAdded = 0;
                output[strings-k] = malloc(i-j+1);
                my_strncpy(output[strings-k],x + j,i-j);
                k--;
            }
        }

    }
    output[strings-k] = malloc(i-j+1);
    my_strncpy(output[strings-k],x + j,i-j);
    output[strings] = NULL;
    return output;
}

