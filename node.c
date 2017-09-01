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

    if (!list_is_empty(&n->head)){
        node *pos;
        cm_string* strs[MAX_CHILDREN];
        size_t node_cnt = 0;
        list_foreach(pos, &n->head, child){
            strs[node_cnt] = render_node(pos);
            ++node_cnt;
        }

        cm_string* child_content = cm_string_cat(strs, node_cnt);
        size_t cnt = 0;
        for (cnt = 0; cnt < node_cnt; ++cnt){
            cm_string_free(strs[cnt]);
        }

        const char* fmt = "<%s>%s<%s>";
        size_t len = child_content->len + n->tag->len * 2 + 4;

        cm_string *render_content = cm_string_pre_alloc(len);
        int i = snprintf(render_content->data, render_content->len + 1, 
                        fmt, n->tag->data, child_content->data, n->tag->data);

        cm_string_free(child_content);
        if (i < render_content->len){
            cm_string_free(render_content);            
            return NULL;
        }

        return render_content;

    }else{
        size_t len = n->tag->len + n->val->len + n->tag->len + 4;
        cm_string* s = cm_string_pre_alloc(len);
        int i = snprintf(s->data, s->len + 1, "<%s>%s<%s>", n->tag->data, n->val->data, n->tag->data);        
        if (i < len){
            cm_string_free(s);
            return NULL;
        }
        return s;
    }
}