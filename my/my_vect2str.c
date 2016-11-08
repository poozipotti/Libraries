#include "my.h"

char *my_vect2str(char **x) {
	char *output;
	int i;
    int stringPlaced = 0;
	int count = 0;
	if (x == NULL) {
		return NULL;
	}
	for (i = 0; x[i] != NULL; ++i) {
        if(my_strlen(x[i])!=0){
            count += my_strlen(x[i]+1);
        }
	}
	output = (char *)malloc(sizeof(char) * count);
	for (i = 0; x[i] != NULL; i++) {
        if(my_strlen(x[i])!=0){
            if(stringPlaced != 0){
                output = my_strcat(output," ");
                output = my_strcat(output, x[i]);
            }else{
                my_strcpy(output,x[i]);
                stringPlaced = 1;
            }
        }
	}
	return output;
}
