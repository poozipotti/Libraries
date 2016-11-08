#include "list.h"

struct s_node* new_node(void* elem,struct s_node* next, struct s_node* previous){
    struct s_node* output = malloc(sizeof(struct s_node));
    output->elem = elem;
    output->next = next;
    output->prev = previous;
    return output;
}
