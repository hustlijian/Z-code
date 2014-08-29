#ifndef COMMON_H
#define COMMON_H

typedef struct{
    int len;
    int * plist;
} blist_t;

void log_message(const char *filename, int line, const char *function, const char *fmt, ...);

void * rlc_alloc(const char *filename, int line, const char *function, size_t size);

int math_pow(int exp, int index);

#define print_error(fmt, args...) log_message(__FILE__, __LINE__, __FUNCTION__, fmt, ##args)

#define zalloc(size) rlc_alloc(__FILE__, __LINE__, __FUNCTION__,size)

#endif
