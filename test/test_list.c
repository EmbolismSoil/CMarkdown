//
// Created by lee on 8/31/17.
//

#include "list.h"

struct mynode{
    int val;
    list_head head;
};

int main(void)
{
    LIST_HEAD(test);

    struct mynode node1 = {1, *new_list_head()};
    struct mynode node2 = {2, *new_list_head()};
    struct mynode node3 = {3, *new_list_head()};
    struct mynode node4 = {4, *new_list_head()};

    struct mynode *p1 = &node1;
    struct mynode *p2 = &node2;
    struct mynode *p3 = &node3;
    struct mynode *p4 = &node4;

#if 0
    list_add(&test, &node1.head);
    list_add(&test, &node2.head);
    list_add(&test, &node3.head);
    list_add(&test, &node4.head);
#else
    list_add_tail(&test, &node1.head);
    list_add_tail(&test, &node2.head);
    list_add_tail(&test, &node3.head);
    list_add_tail(&test, &node4.head);
#endif


    list_head *pos;
    struct mynode *nodepos;

    list_foreach(nodepos, &test, child){
        printf("val = %d\n", nodepos->val);        
    }

    return 0;
}