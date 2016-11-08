#include "list.h"

void debug_char(struct s_node* head){

    if(head == NULL){
        my_str("NULL");
        return;
    }
    if(head->prev == NULL){
        my_str("( NULL <- ");
    }else{
        my_str("( ");
        print_char(head->prev);
        my_str(" <- ");
    }
    print_char(head);
    my_str(" -> ");
    if(head->next == NULL){
        my_str("NULL ),");
    }else{
        print_char(head->next);
        my_str(" ), ");
    }
    while(head->next != NULL){
        head = head->next;
        if(head->prev == NULL){
            my_str("( NULL <- ");
        }else{
            my_str("( ");
            print_char(head->prev);
            my_str(" <- ");
        }
        print_char(head);
        my_str(" -> ");
        if(head->next == NULL){
            my_str("NULL ),");
        }else{
            print_char(head->next);
            my_str(" ), ");
        }
    }
}

