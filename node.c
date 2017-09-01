//
// Created by lee on 8/31/17.
//

#include "node.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "utils.h"
#include "list.h"

cm_string* render_node(node *n)
{
    assert(n && n->tag);                

    if (!list_is_empty(&n->children)){
        node *pos;
        cm_string* strs[MAX_CHILDREN];
        size_t node_cnt = 0;
        list_foreach(pos, &n->children, children){
            strs[node_cnt] = render_node(pos);
            ++node_cnt;
        }

        cm_string* render_content = cm_string_cat(strs, node_cnt);
        
        size_t cnt = 0;
        for (cnt = 0; cnt < node_cnt; ++cnt){
            cm_string_free(strs[cnt]);
        }

        return render_content;

    }else{
        cm_string *fmt = cm_string_from_raw("<%s>%s<%s>", 10);
        cm_string* s = cm_string_from_foramt(fmt, 3, n->tag, n->val, n->tag);
        
        cm_string_free(fmt);
        return s;
    }
}