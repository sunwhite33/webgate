/*
 * Copyright (C) Chen Xi.
 *
 * str wrapper.
 * Written by Chen Xi <sunwhite@gmail.com> Jan 2023
 */
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "wg_types.h"
#include "wg_str.h"

str_t *new_str(void)
{
    str_t *str = (str_t *) malloc(sizeof(str_t));
    if (str == NULL)
    {
        return NULL;
    }
    memset(str, 0, sizeof(str_t));
    char *byte = (char *) malloc(sizeof(char));
    byte[0] = ZERO;
    str->byte = byte;
    return str;
}

str_t *init_str(const char *str)
{
    if (str == NULL)
    {
        return NULL;
    }
    str_t *new_str = new_str();
    new_str->size = strlen(str);
    char *byte = (char *) malloc(new_str->size + 1);
    memcpy(byte, str, new_str->size);
    new_str->byte = byte;
    return new_str;
}

long size(const str_t *str)
{
    if (str == NULL)
    {
        return 0;
    }
    return str->size;
}

str_t *upper(str_t *str)
{
    if (str == NULL)
    {
        return str;
    }
    char *tmp = str->byte;
    for (int i = 0; i < str->size; i++)
    {
        if (tmp[i] < 'a' || tmp[i] > 'z')
        {
            continue;
        }
        tmp[i] += 32;
    }
    return str;
}

str_t *lower(str_t *str)
{
    if (str == NULL)
    {
        return str;
    }
    char *tmp = str->byte;
    for (int i = 0; i < str->size; i++)
    {
        if (tmp[i] < 'A' || tmp[i] > 'Z')
        {
            continue;
        }
        tmp[i] -= 32;
    }
    return str;
}

str_t *append(str_t *dest, const str_t *src)
{
    if (src == NULL || src->size <= 0)
    {
        return dest;
    }
    long len = dest->size + src->size + 1;
    char *tmp = (char *) malloc(sizeof(char) * len);
    memcpy(tmp, dest->byte, dest->size);
    memcpy(tmp + dest->size, src->byte, src->size);
    free(dest->byte);
    dest->size = len - 1;
    dest->byte = tmp;
    return dest;
}

char char_at(long index, const str_t *str)
{
    if (index < 0 || index > str->size || str->byte == NULL)
    {
        return ZERO;
    }
    char *byte = str->byte;
    return byte[index];
}

noreturn void free_str(str_t *str)
{
    if (str == NULL)
    {
        return;
    }
    if (str->byte == NULL)
    {
        return;
    }
    free(str->byte);
    free(str);
    str = NULL;
}

str_t *substr(const str_t *str, long index, long size)
{
    if (str == NULL || str->byte == NULL || index < 0 || size < 0)
    {
        return NULL;
    }
    if (index + size > str->size)
    {
        len = str->size - index;
    }
    str_t *sub_str = new_str();
    sub_str->size = len;
    sub_str->byte = (char *) malloc(sizeof(char) * (len + 1));
    for (long i = 0, j = index; i < len; i++, j++)
    {
        sub_str->byte[i] = str->byte[j];
    }
    return sub_str;
}

BOOL contain_str(const str_t *str, const str_t *pattern)
{
    if (str1 == NULL || partten == NULL)
    {
        return FALSE;
    }
    if (pattern->size > str->size)
    {
        return FALSE;
    }
    for (int i = 0; i < str->size; i++)
    {
        for (int j = 0; j < pattern->size; j++)
        {
            if (i + j >= str->size)
            {
                return FALSE;
            }
            int res1 = (pattern->byte[j] == str->byte[i + j]);
            if (res1 == 0)
            {
                break;
            }
            int res2 = (j == partten->size - 1);
            if (res1 == res2)
            {
                return TRUE;
            }
        }
    }
    return FALSE;
}

BOOL is_equal(const str_t *str1, const str_t *str2)
{
    if (str1 == NULL && str2 == NULL)
    {
        return TRUE;
    }
    if (str1->size != str2->size)
    {
        return FALSE;
    }
    BOOL res = memcmp(str1->byte, str2->byte, str2->size);
    return res == 1 ? TRUE : FALSE;
}
