#include "list.h"
void* remove_node(struct s_node** node){
    void * output= NULL;
    struct s_node * temp = *node;
    assert(node != NULL);
    if(*node != NULL){
        output = (*node)->elem;
        if((*node)->next != NULL && (*node)->prev !=NULL){ /*middle*/
            (*node)->prev->next = (*node)->next;
            (*node)->next->prev = (*node)->prev;
        }else if((*node)->prev !=NULL && (*node)->next ==NULL){ /*Last*/
            (*node)->prev->next = NULL;
            (*node)=NULL;
        }else if((*node)->next !=NULL && (*node)->prev ==NULL){ /*Head*/
            (*node)->next->prev = NULL;
            (*node) = (*node)->next;
        }else{/*single node*/
            *node = NULL;
        }
    }
    free(temp);
    return output;
}

