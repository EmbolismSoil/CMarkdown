#include "node.h"
#include "utils.h"

int main(void)
{
    node n1 = {.tag = cm_string_from_raw("html", 4), .val = NULL, .properties = NULL};
    LIST_INIT_HEAD(&n1.head);

    node n2 = {.tag = cm_string_from_raw("body", 4), .val = NULL, .properties = NULL};
    LIST_INIT_HEAD(&n2.head);

    node n3 = {.tag = cm_string_from_raw("p", 1), .val = cm_string_from_raw("hello world", 11), .properties = NULL};
    LIST_INIT_HEAD(&n3.head);

    list_add_tail(&n1.head, &n2.child);
    list_add_tail(&n2.head, &n3.child);

    cm_string* content = render_node(&n1);
    printf(content->data);
    return 0;
}