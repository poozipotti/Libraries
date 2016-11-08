#include "list.h"
void traverse_string(struct s_node* head){
    if(head == NULL){
        my_char(' ');
        return;
    }
    print_string(head);
    my_char(' ');
    while(head->next != NULL){
        my_str(print_string(head->next));
        my_char(' ');
        head = head->next;
    }
}
