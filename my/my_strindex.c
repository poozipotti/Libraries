/*
 * InputString is the String to be searched and searchChar is a character
 * to be searched for
 * returns a pinter to the first char in the string which matches.
 * return NULL if the letter is not found.
 */
#include "my.h"

char* my_strindex(char * inputString , char searchChar ){
    while(* inputString){
        if(* inputString == searchChar){
            return inputString;
        }
        inputString ++;
    }
    return NULL;
}

