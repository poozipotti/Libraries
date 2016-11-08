#include "my.h"

char *my_strcat(char * dst, char * src){
    my_strcpy(my_strlen(dst)+dst,src);
    return dst;
}
