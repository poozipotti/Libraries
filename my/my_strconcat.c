#include "my.h"

char *my_strconcat(char*a , char*b){
    char * temp = (char *)malloc(my_strlen(a) + my_strlen(b) + 1);
    my_strcpy(temp,a);
    my_strcat(temp,b);
    return temp;
}
