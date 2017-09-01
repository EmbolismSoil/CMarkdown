#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#define CM_MALLOC(len) malloc(len)
#define CM_FREE(p) free(p)

typedef struct _cm_string{
    size_t len;
    size_t ref_cnt;
    struct _cm_string *cpy;
    char *data;    
}cm_string;

extern void cm_string_free(cm_string* );
extern int cm_sprintf(cm_string* buf, const char* fmt, ...);
extern cm_string* cm_string_from_raw(const char* raw, size_t len);
extern cm_string* cm_string_pre_alloc(size_t len);
extern void cm_string_free(cm_string *str);
extern cm_string* cm_string_cpy(cm_string* src);
extern cm_string* cm_string_deep_cpy(cm_string *src);
extern int cm_sprintf(cm_string *buf, const char* fmt, ...);
extern cm_string* cm_string_from_foramt(cm_string *fmt, uint8_t args, ...);

#endif