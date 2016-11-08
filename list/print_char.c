#include "list.h"

void print_char(struct s_node* node){
    if(node->elem == NULL){
        my_str("NULL");
        return;
    }
    my_char(*(char*)node->elem);
}
