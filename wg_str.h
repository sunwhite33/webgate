/*
 * Copyright (C) Chen Xi.
 *
 * str wrapper.
 * Written by Chen Xi <sunwhite@gmail.com> Jan 2023
 */

#ifndef _STR_H_
#define _STR_H_

typedef struct
{
    long size;
    char *byte;
} str_t;

str_t *new_str(void);

str_t *init_str(const str_t *str);

long size(const str_t *str);

str_t *upper(str_t *str);

str_t *lower(str_t *str);

str_t *append(str_t *dest, const str_t *src);

char char_at(long index, const str_t *str);

void free_str(str_t *str);

str_t *substr(const str_t *str, long index, long size);

int contain_str(const str_t *str, const str_t *pattern);

int is_equal(const str_t *str1, const str_t *str2);

#endif /* _STR_H */
