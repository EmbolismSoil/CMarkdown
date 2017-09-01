#include "node.h"
#include "utils.h"

int main(void)
{
    node n1 = {.tag = cm_string_from_raw("html", 4), .val = NULL, .properties = NULL};
    LIST_INIT_HEAD(&n1.children);

    node n2 = {.tag = cm_string_from_raw("body", 4), .val = NULL, .properties = NULL};
    LIST_INIT_HEAD(&n2.children);

    node n3 = {.tag = cm_string_from_raw("p", 1), .val = cm_string_from_raw("hello world", 11), .properties = NULL};
    LIST_INIT_HEAD(&n3.children);    

    n1.children.next = &n2.children;
    n2.children.prev = &n1.children;

    n2.children.next = &n3.children;
    n3.children.prev = &n2.children;

    //list_add_tail(&n1.children, &n2.children);
    //list_add_tail(&n2.children, &n3.children);

    cm_string* content = render_node(&n1);
    printf(content->data);
    return 0;
}