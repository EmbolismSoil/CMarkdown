//
// Created by lee on 8/31/17.
//

#include "node.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "utils.h"
#include "list.h"

const cm_string* render_node(node *n)
{
    assert(n && n->tag);                

    if (n->properties){
        node *pos;

        list_foreach(pos, &n->children, children){
                
        }
    
    }else{
        cm_string *fmt = cm_string_from_raw("<%s>%s<%s>", 10);
        cm_string* s = cm_string_from_foramt(fmt, 3, n->tag, n->val, n->tag);

        return s;
    }
}