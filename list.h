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

static inline void __list_add(list_head* prev, list_head* next, list_head* node)
{
    node->prev = prev;
    prev->next = node;

    node->next = next;
    next->prev = node;
}

 static inline void list_add_tail(list_head *head, list_head* node)
{
    assert(head && node);
    __list_add(head->prev, head, node);
}

 static inline void list_add(list_head* head, list_head* node)
{
    assert(head && node);    
    __list_add(head, head->next, node);
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

#define list_foreach(pos, phead, member)\
    for (pos = container_of((phead)->next, typeof(*(pos)), member); \
            &((pos)->member) != (phead); pos = container_of((pos)->member.next, typeof(*(pos)), member))


#define list_is_empty(phead) \
    ((phead)->next == (phead) && (phead)->prev == (phead))
#endif //CMARKDOWN_LIST_H
