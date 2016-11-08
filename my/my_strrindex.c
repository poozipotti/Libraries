/*
 * InputString is the String to be searched and searchChar is a character
 * to be searched for
 * returns a printer to the last char in the string which matches.
 * return NULL if the letter is not found.
 */
#include "my.h"

char * my_strrindex(char * inputString, char searchChar){
    char * temp = 0;
    while(* inputString){
        if(* inputString == searchChar){
            temp = inputString;
        }
        inputString ++;
    }

        return temp;
}
