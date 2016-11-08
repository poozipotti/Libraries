#include "list.h"
void traverse_int(struct s_node* head){
    if(head == NULL){
        my_char(' ');
        return;
    }
    print_int(head);
    my_char(' ');
    while(head->next != NULL){
        print_int(head->next);
        my_char(' ');
        head = head->next;
    }
}
