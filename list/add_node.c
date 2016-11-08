#include "list.h"

void add_node(struct s_node* node, struct s_node** head){
    assert(node != NULL);
    assert(head != NULL);
    assert(node->elem != NULL);
    (*head)->prev = node;
    node->next = *head;
    node->prev = NULL;
    *head = node;
}
