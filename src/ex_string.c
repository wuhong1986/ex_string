/* {{{
 * =============================================================================
 *      Filename    :   exstr_ing.c
 *      Description :
 *      Created     :   2015-08-22 20:08:40
 *      Author      :   Wu Hong
 * =============================================================================
 }}} */

#include <stdlib.h>
#include <string.h>
#include "../include/ex_string.h"

char* exstr_dup(const char *str)
{
    int   len = 0;
    char *buf = NULL;

    if (!str) return NULL;

    len = strlen(str) + 1;
    buf = (char*)malloc(len);

    if(buf) { memcpy(buf, str, len); }

    return buf;
}

char* exstr_ndup(const char *str, size_t n)
{
    char* str_copy = (char*)malloc(n+1);

    if (str_copy) {
        strncpy(str_copy, str, n);
        str_copy[n] = '\0';
    }

    return str_copy;
}

bool exstr_starts_with(const char *str, const char *start)
{
    for (; ; str++, start++) {
        if (!*start) {
            return true;
        } else if (*str != *start) {
            return false;
        }
    }
}

bool exstr_ends_with(const char *str, const char *end)
{
    int end_len = 0;
    int str_len = 0;

    if (NULL == str || NULL == end) return false;

    end_len = strlen(end);
    str_len = strlen(str);

    return str_len < end_len
         ? false
         : !strcmp(str + str_len - end_len, end);
}

int   exstr_substr_count(const char *str, const char *sub)
{
    char *pos = (char *)str;
    int i = 0;
    int l = 0;

    if (NULL == str || NULL == sub) return -1;

    l = strlen(sub);

    while ((pos = strstr(pos, sub))) {
        pos += l;
        i++;
    }

    return i;
}

char* exstr_replace(const char *str, const char *sub, const char *replace)
{
    char *pos = (char *) str;
    char *result = NULL;
    char *current = NULL;
    int count = exstr_substr_count(str, sub);
    int size = 0;

    if (0 >= count) return exstr_dup(str);

    size = (strlen(str) - (strlen(sub) * count) + strlen(replace) * count) + 1;

    result = (char *) malloc(size);
    if (NULL == result) return NULL;
    memset(result, '\0', size);

    while ((current = strstr(pos, sub))) {
        int len = current - pos;
        strncat(result, pos, len);
        strncat(result, replace, strlen(replace));
        pos = current + strlen(sub);
    }

    if (pos != (str + strlen(str))) {
        strncat(result, pos, (str - pos));
    }

    return result;
}

const char* exstr_bool(bool value)
{
    return value ? "true" : "false";
}

const char* exstr_Bool(bool value)
{
    return value ? "True" : "False";
}

const char* exstr_BOOL(bool value)
{
    return value ? "TRUE" : "FALSE";
}

const char* exstr_onoff(bool value)
{
    return value ? "on" : "off";
}

const char* exstr_OnOff(bool value)
{
    return value ? "On" : "Off";
}

const char* exstr_ONOFF(bool value)
{
    return value ? "ON" : "OFF";
}
