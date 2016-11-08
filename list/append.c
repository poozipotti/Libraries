#include "list.h"

void append(struct s_node* node, struct s_node** head){
    struct s_node* current = *head;
    if(head == NULL || *head == node){
        return;
    }
    if(*head == NULL || (*head)->next == NULL){
        add_node(node, head);
        return;
    }
    while(current->next != NULL){
        current = current->next;
    }
    current->next = node;
    node-> prev = current;
}
