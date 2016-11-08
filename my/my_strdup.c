#include "my.h"

char *my_strdup(char *str){
    char* output = NULL;
    if(str == NULL){
        return output;
    }
    output = (char*) (malloc (my_strlen(str)+1));
    my_strcpy(output,str);
    return output;
}
