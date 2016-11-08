#include "list.h"

int count_s_nodes(struct s_node* head){
    unsigned int temp=1;
    if(head == NULL){
        return 0;
    }
    while(head->next != NULL){
        temp ++;
        head = head->next;
    }
    return temp;

}
