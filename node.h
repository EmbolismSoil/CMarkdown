//
// Created by lee on 8/31/17.
//

#ifndef CMARKDOWN_NODE_H
#define CMARKDOWN_NODE_H

#include "list.h"
#include "utils.h"

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
    list_head children;
}node;

#endif //CMARKDOWN_NODE_H
