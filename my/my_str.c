#include "my.h"
/*
 * input inputString is a char *,prints inputString to the console
 */
void my_str(char * inputString){
    if(inputString != NULL){
        while(0 != * inputString){
            my_char(* inputString);
            inputString ++;
        }
    }
}
