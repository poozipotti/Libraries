#include "my.h"
/* inputString is a string that is reversed in place
 * returns the length of input string
 */
int my_revstr(char * inputString){
    int end = my_strlen(inputString);
    int i= 0;
    int j= end -1;
    if (inputString == NULL){
        return -1;
    }
    while(i<j){
       inputString[end] = inputString[i];
       inputString[i] = inputString[j];
       inputString[j] = inputString[end];
       i++;
       j--;
    }
    inputString[end] = '\0';
    return end;
}
