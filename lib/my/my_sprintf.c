/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** The Ultime Printf
*/

#include <stdarg.h>
#include "my.h"
#include <stdio.h>
#include <stdlib.h>

static int free_flags(void *f);

static flagstruct *create_flag(void (*f)(void *),
                    void (*f2)(void *, char *),
                    char *param, char *prefix)
{
    flagstruct *flag = malloc(sizeof(flagstruct));
    flag->func = f;
    flag->pt = f2;
    flag->param = param;
    flag->prefix = prefix;
    return (flag);
}

static void init_dictionary(dictionary **flags)
{
    dictionary_add(flags, "s", create_flag(my_sputstr_void, NULL, NULL, NULL));
    dictionary_add(flags, "c", create_flag(my_sputchar_void, NULL, NULL, NULL));
    dictionary_add(flags, "d", create_flag(my_sput_nbr_void, NULL, NULL, NULL));
    dictionary_add(flags, "i", create_flag(my_sput_nbr_void, NULL, NULL, NULL));
}

static void get_flags(char *flag, va_list print, dictionary *flags, char *buf)
{
    if (dictionary_key_exists(&flags, flag)) {
        flagstruct *value = (flagstruct *) dictionary_getvalue(&flags, flag);
        if (value->func != NULL)
            value->func(va_arg(print, void *), buf);
        else if (value->pt != NULL) {
            if (value->prefix != NULL)
                my_putstr(value->prefix);
            value->pt(va_arg(print, void *), value->param, buf);
        }
    }
}

void my_sprintf(char *buffer, const char *str, ... )
{
    va_list print;
    va_start(print, str);
    char flag[5];
    int count = 0;
    dictionary *flags = NULL;
    init_dictionary(&flags);
    char ch[800] = "";

    for (int i = 0; str[i]; i++) {
        if (str[i] == '%') {
            i++;
            flag[0] = str[i];
            if (str[i] == '#') {
                i++;
                flag[1] = str[i];
                flag[2] = '\0';
            } else
                flag[1] = '\0';
            get_flags(flag, print, flags, &ch);
        }
        else
            my_sputchar(str[i], &ch);
        count++;
    }
    my_strcpy(buffer, ch);
    va_end(print);
    dictionary_foreach_value(flags, free_flags);
    dictionary_delete_all(flags);
}

static int free_flags(void *f)
{
    flagstruct *flag = (flagstruct *) f;
    free(flag);
    return (1);
}