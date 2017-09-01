#include "utils.h"
#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>

#define BUILD_CM_STRING(str, from, _len) do{\
    str->data = (char*)str + sizeof(*str);\
    str->ref_cnt = 1;\
    str->cpy = from;\
    str->len = _len;\
}while(0)

cm_string* cm_string_from_raw(const char* raw, size_t len)
{
    assert(raw);
    cm_string* str = CM_MALLOC(sizeof(*str) + len + 1);
    BUILD_CM_STRING(str, NULL, len);
    
    strncpy(str->data, raw, len);

    return str;
}

cm_string* cm_string_pre_alloc(size_t len)
{
    assert(len >= 0);
    
    cm_string *str = CM_MALLOC(sizeof(*str) + len + 1);
    BUILD_CM_STRING(str, NULL, len);

    return str;
}

void cm_string_free(cm_string *str)
{
    assert(str);

    if (str->cpy){
        --str->cpy->ref_cnt;
    }

    if (--str->ref_cnt == 0){
        CM_FREE(str);            
    }    
}

cm_string* cm_string_cpy(cm_string* src)
{
    assert(src);
    cm_string* cpy = CM_MALLOC(sizeof(*src));

    BUILD_CM_STRING(cpy, src, src->len);
    ++src->ref_cnt;
    
    return cpy;
}

cm_string* cm_string_deep_cpy(cm_string *src)
{
    assert(src);

    cm_string* cpy = (cm_string*)CM_MALLOC(sizeof(*src) + src->len + 1);
    assert(cpy);

    cpy->data = (char*)cpy + sizeof(*cpy);
    cpy->len = src->len;
    cpy->cpy = NULL;
    cpy->ref_cnt = 1;

    strncpy(cpy->data, src->data, cpy->len);

    return cpy;
}

int cm_sprintf(cm_string *buf, const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    int i = vsnprintf(buf->data, buf->len, fmt, args);
    va_end(args);

    return i;
}

cm_string* cm_string_from_foramt(cm_string *fmt, uint8_t args, ...)
{
    uint8_t cnt;
    ssize_t len = fmt->len - 2*args;    
    va_list arg_list;
    
    va_start(arg_list, args);
    for (cnt = 0; cnt < args; ++cnt)
    {
        cm_string* arg = va_arg(arg_list, cm_string*);
        len += arg->len;        
    }
    va_end(arg_list);

    cm_string *buf = cm_string_pre_alloc(len);
        
    va_start(arg_list, args);    
    int i = vsnprintf(buf->data, buf->len, fmt->data, arg_list);
    va_end(arg_list);

    if (i < buf->len){
        cm_string_free(buf);
        return NULL;
    }else{
        return buf;
    }    
}
