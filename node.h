//
// Created by lee on 8/31/17.
//

#ifndef CMARKDOWN_NODE_H
#define CMARKDOWN_NODE_H

#include "list.h"

typedef struct _property{
    char* name;
    char* value;

    struct _property *next;
}property;

typedef struct _node{
    char* tag;
    property *properties;
    char* val;

    struct _node* children;
}node;

#endif //CMARKDOWN_NODE_H
