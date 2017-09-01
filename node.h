//
// Created by lee on 8/31/17.
//

#ifndef CMARKDOWN_NODE_H
#define CMARKDOWN_NODE_H

#include "list.h"
#include "utils.h"

#define MAX_CHILDREN 4096

typedef struct _property{
    cm_string *name;
    cm_string *value;
    struct _property *next;
}property;

typedef struct _node{
    cm_string* tag;
    cm_string* val;
    property *properties;

    //struct _node* children;
    list_head child;
    list_head head;
}node;

extern cm_string* render_node(node *n);
#endif //CMARKDOWN_NODE_H
