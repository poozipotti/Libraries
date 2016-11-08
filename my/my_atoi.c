#include "my.h"

int my_atoi(char * input){
    int negative = 1;
    int power = 1;
    int temp = 0;
    if(input == NULL){
        return 0;
    }
    while(*input < '0' || *input >'9'){
        if(*input == '\0'){
            return 0;
        }
        negative *= (*input == '-') ? -1 : 1;
        input ++;
    }
    while(*input >= '0' && *input <= '9'){
        input ++;
    }
    input --;
    while(*input >= '0' && *input <= '9'){
        temp += power * (*input - '0') * negative;
        power *= 10;
        input --;
    }
    return temp;
}
