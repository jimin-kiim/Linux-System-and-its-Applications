#ifndef _LINKED_LIST_IMPL_H
#define _LINKED_LIST_IMPL_H


struct my_node {
        struct list_head list;
        unsigned int data;
};

struct list_head my_list;

void *add_to_list(int thread_id, int range_bound[]);
int search_list(int thread_id, void *data, int range_bound[]);
int delete_from_list(int thread_id, int range_bound[]);


#endif