#include "list.h"

char* print_string(struct s_node* node){
    if(node->elem == NULL){
        return "NULL";
    }
    return ((char *)node->elem);
}
