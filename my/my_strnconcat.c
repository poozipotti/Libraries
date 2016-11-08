#include "my.h"

char *my_strnconcat(char *a , char *b, int n){
    char * temp = (char *)malloc(my_strlen(a) + ((n>my_strlen(b) ? n : my_strlen(b))) + 1);
    if(a == NULL){
        my_strncpy(temp,b,n);
        return temp;
    }
    my_strcpy(temp,a);
    my_strncpy(temp+my_strlen(a),b,n);
    return temp;
}
