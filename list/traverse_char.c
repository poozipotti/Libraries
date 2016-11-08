#include "list.h"
void traverse_char(struct s_node* head){
    if(head == NULL){
        my_char(' ');
        return;
    }
    print_char(head);
    my_char(' ');
    while(head->next != NULL){
        print_char(head->next);
        my_char(' ');
        head = head->next;
    }
}
