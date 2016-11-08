#include "my.h"
/* intput is in int, inputString is a char *, intput is
 * converted to a number that can be represented by the
 * intput String, and that number is displayed
 */
void my_num_base (int intput, char * inputString){
    int isNegative =  ((intput < 0) ? 1: 0);
    int base=0;
    long power = 1;
    if(inputString == NULL || inputString[0] == 0){
        my_str("bad input string \n");
        return;
    }
    if(intput == 0){
        my_char(inputString[0]);
        return;
    }
    if(isNegative){
        my_char('-');
        power = -1;
    }
    base = my_strlen(inputString);
    if(base ==1){
        while(intput > 0){
            my_char(* inputString);
            intput --;
        }
        return;
    }
    while((intput / power ) >= base){
        power *= base;
    }
    while(((isNegative ? -1 : 1)*power) > 0){
        my_char(inputString[intput/power]);
        intput = intput % power;
        power /= base;
    }
}

