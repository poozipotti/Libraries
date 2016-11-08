
/*
 * InputString is the String to be searched and searchChar is a character
 * to be searched for
 * returns a pinter to the first char in the string which matches.
 * return NULL if the letter is not found.
 */
#include "my.h"

int my_strfind(char * src , char c ){
    int temp = 0;
    if(c == '\0'){
        return my_strlen(src);
    }
    if(!src)
        return -1;
    while(* src){
        if(* src == c){
            return temp;
        }
        temp ++;
        src ++;
    }
    return -1;
}

