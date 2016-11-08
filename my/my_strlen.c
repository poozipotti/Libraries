/*
 * calculates the length of a string not including the null terminator.
 * Null string is of length -1
 */

int my_strlen(char* inputString){
    int temp =0;
    if(!inputString){
        return -1;
    }
    while(* inputString){
        temp ++;
        inputString ++;
    }
    return temp;
}
