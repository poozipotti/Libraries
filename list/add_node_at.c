#include "list.h"
void add_node_at(struct s_node* node, struct s_node** head, int n){
    struct s_node* current = *head;
    assert(n>=0);
    assert(head!=NULL);
    assert(node != NULL);
    assert(node->elem != NULL);
    if(*head == NULL || n==0){
        add_node(node, head);
        return;
    }
    while(current->next != NULL && n > 1){
        current = current->next;
        n--;
    }
    node->prev = current;
    node->next = current->next;
    if(node->next != NULL)
    node->next->prev = node;
    current->next = node;

}
