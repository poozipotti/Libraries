#include "list.h"

void debug_string(struct s_node* head){

    if(head == NULL){
        my_str("NULL");
        return;
    }
    if(head->prev == NULL){
        my_str("( NULL <- ");
    }else{
        my_str("( ");
        my_str(print_string(head->prev));
        my_str(" <- ");
    }
    my_str(print_string(head));
    my_str(" -> ");
    if(head->next == NULL){
        my_str("NULL ),");
    }else{
        my_str(print_string(head->next));
        my_str(" ), ");
    }
    while(head->next != NULL){
        head = head->next;
        if(head->prev == NULL){
            my_str("( NULL <- ");
        }else{
            my_str("( ");
            my_str(print_string(head->prev));
            my_str(" <- ");
        }
        my_str(print_string(head));
        my_str(" -> ");
        if(head->next == NULL){
            my_str("NULL ),");
        }else{
            my_str(print_string(head->next));
            my_str(" ), ");
        }
    }
}

