//
// Created by lee on 8/31/17.
//

#include "node.h"
#include <assert.h>
#include <stdio.h>

const char* render_node(node *n)
{
    assert(n && n->tag);
    char buf[2048];
    if (n->val){
        sprintf(buf, "<%s>%s</%s>", n->tag, n->val, n->tag);
    }
}