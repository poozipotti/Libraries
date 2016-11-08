/*
 * src is the String to be searched and c is a character
 * to be searched for
 * returns a printer to the last char in the string which matches.
 * return NULL if the letter is not found.
 */
#include "my.h"

int my_strrfind(char * src, char c){
    int temp = -1;
    int count = 0;
    if(c == '\0'){
        return my_strlen(src);
    }
    if(!src)
        return -1;
    while(* src){
        if(* src == c){
           temp = count;
        }
        src ++;
        count ++;
    }
        return temp;
}
