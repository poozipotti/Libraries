#include "list.h"

struct s_node* node_at(struct s_node* head, int n){
    assert(n>=0);
    if(head == NULL){
        return NULL;
    }
    while( n>=0 || head->next != NULL){
        head = head->next;
        n--;
    }
    return head;
}

