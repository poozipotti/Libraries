#include "list.h"

void* remove_last(struct s_node** head){
  return remove_node_at(head, count_s_nodes(*head)-1);
}
