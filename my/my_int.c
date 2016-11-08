#include "my.h"
/*input  intput is an int, prints a given signed integer as a string
 *
 */

void my_int(int intput){ /* get it?*/
    int isNegative =  ((intput < 0) ? 1 : 0);
    long power = 1;
    if(intput == 0){
        my_char('0');
        return;
    }
    if(isNegative){
        my_char('-');
        power = -1;
    }

    while(((intput) / power) >= 10){
        power*=10;
    }

    while(((isNegative ? -1 : 1)*power) > 0){
        my_char(intput/power + '0');
        intput %= power;
        power /=10;
    }
}


