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

int free_flags(void *f);

flag_t *create_flag(void (*f)(void *), void (*f2)(void *, char *),
                                        char *param, char *prefix)
{
    flag_t *flag = malloc(sizeof(flag_t));
    flag->func = f;
    flag->pt = f2;
    flag->param = param;
    flag->prefix = prefix;
    return (flag);
}

void init_dictionary(dictionary **flags)
{
    dictionary_add(flags, "s", create_flag(my_putstr_void, NULL, NULL, NULL));
    dictionary_add(flags, "c", create_flag(my_putchar_void, NULL, NULL, NULL));
    dictionary_add(flags, "d", create_flag(my_put_nbr_void, NULL, NULL, NULL));
    dictionary_add(flags, "i", create_flag(my_put_nbr_void, NULL, NULL, NULL));
    dictionary_add(flags, "o", create_flag(NULL, my_putbase_void,
                                                    "01234567", NULL));
    dictionary_add(flags, "x", create_flag(NULL, my_putbase_void,
                                                    "0123456789abcdef", NULL));
    dictionary_add(flags, "X", create_flag(NULL, my_putbase_void,
                                                    "0123456789ABCDEF", NULL));
    dictionary_add(flags, "#o", create_flag(NULL, my_putbase_void,
                                                    "01234567", "0"));
    dictionary_add(flags, "#x", create_flag(NULL, my_putbase_void,
                                                    "0123456789abcdef", "0x"));
    dictionary_add(flags, "#X", create_flag(NULL, my_putbase_void,
                                                    "0123456789ABCDEF", "0X"));
}

void get_flag(char *flag, va_list print, int *count, dictionary *flags)
{
    if (dictionary_key_exists(&flags, flag)) {
        flag_t *value = (flag_t *) dictionary_getvalue(&flags, flag);
        if (value->func != NULL)
            value->func(va_arg(print, void *));
        else if (value->pt != NULL) {
            if (value->prefix != NULL)
                my_putstr(value->prefix);
            value->pt(va_arg(print, void *), value->param);
        }
    }
}

void my_printf(char *str, ...)
{
    va_list print;
    va_start(print, str);
    char flag[5];
    int count = 0;
    dictionary *flags = NULL;
    init_dictionary(&flags);

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
            get_flag(flag, print, &count, flags);
        }
        else
            my_putchar(str[i]);
        count++;
    }
    va_end(print);
    dictionary_foreach_value(flags, free_flags);
    dictionary_delete_all(flags);
}

int free_flags(void *f)
{
    flag_t *flag = (flag_t *) f;
    free(flag);
    return (1);
}