#include "list.h"
void* remove_node_at(struct s_node** head, int n){
    struct s_node * start = *head;
    void * output;
    assert(n>=0);
    assert(head != NULL);
    if(n == 0 || (*head)->next == NULL){
        return remove_node(head);
    }
    while(n>0 && (*head)->next != NULL){
        *head = (*head)->next;
        n--;
    }
    output = remove_node(head);
    *head = start;
    return output;
}
