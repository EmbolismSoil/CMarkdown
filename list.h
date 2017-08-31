//
// Created by lee on 8/31/17.
//

#ifndef CMARKDOWN_LIST_H
#define CMARKDOWN_LIST_H

#include <malloc.h>
#include "assert.h"

typedef struct _list_head{
    struct _list_head *prev;
    struct _list_head *next;
} list_head;

#define __offset(container, member) \
    ((size_t)(&((const container*)0)->member))

#define container_of(phead, container, member) \
    ((container*)((char*)(phead) - __offset(container, member)))


#define LIST_INIT_HEAD(head) do{\
    (head)->prev = (head);\
    (head)->next = (head);\
}while(0)


#define LIST_HEAD(name) \
    list_head name;\
    LIST_INIT_HEAD(&name)


 static inline void list_add_tail(list_head *head, list_head* node)
{
    assert(head && node);

    node->next = head;
    node->prev = head->prev;

    if (node->prev){
        node->prev->next = node;
    }

    head->prev = node;

    if (head->next == NULL){
        head->next = node;
    }
}

 static inline void list_add(list_head* head, list_head* node)
{
    assert(head && node);

    node->next = head->next;
    node->prev = head;

    if (node->next){
        node->next->prev =  node;
    }

    head->next = node;
}

 static inline void list_del(list_head* node)
{
    assert(node);

    if (node->prev){
        node->prev->next = node->next;
        if (node->next){
            node->next->prev = node->prev;
        }
    }
}

static inline list_head* new_list_head()
{
    list_head* head = (list_head*)malloc(sizeof(*head));
    assert(head);

    LIST_INIT_HEAD(head);

    return head;
}



#endif //CMARKDOWN_LIST_H
