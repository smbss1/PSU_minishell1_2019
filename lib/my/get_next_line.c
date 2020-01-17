/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** Get line in a fd
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "garbage.h"

void malloc_buffer(gc_t *gc, char **buffer, const int fd)
{
    if (*buffer == NULL || *buffer[0] == '\0') {
        int byte = 0;
        *buffer = gc_malloc(gc, sizeof(char) * (READ_SIZE + 1));
        if (*buffer == NULL)
            return;
        byte = read(fd, *buffer, READ_SIZE);
        if (byte < 0) {
            (*buffer)[byte] = '\0';
            return;
        }
        (*buffer)[byte] = '\0';
    }
}

char *malloc_result(gc_t *gc, char **result)
{
    *result = gc_malloc(gc, sizeof(char) * (READ_SIZE + 1));
    return (*result);
}

void copy(char *result, char *str1, char *str2, int *j)
{
    for (int i = 0; str1[i]; i++, *j += 1)
        result[*j] = str1[i];
    for (int i = 0; str2[i]; i++, *j += 1)
        result[*j] = str2[i];
}

char *str_cat_dup(gc_t *gc, char *str1, char *str2)
{
    char *result = NULL;
    int len_str1 = 0;
    int len_str2 = 0;
    int j = 0;

    if (str2 == NULL)
        return (str1);
    if (str1 == NULL)
        return (str2);
    while (str1[len_str1++]);
    while (str2[len_str2++]);
    int len3 = len_str1 + len_str2 + 1;
    result = gc_malloc(gc, sizeof(char) * len3);
    if (result == NULL)
        return (NULL);
    copy(result, str1, str2, &j);
    result[j] = '\0';
    return (result);
}

char *get_next_line(int fd)
{
    gc_t *gc = get_garbage();
    static char *buffer;
    char *ret = NULL;
    int i = 0;

    malloc_buffer(gc, &buffer, fd);
    if (buffer == NULL || buffer[0] == '\0')
        return (NULL);
    if (malloc_result(gc, &ret) == NULL)
        return (NULL);
    while (buffer[0] != '\0' && (i == 0 || *(buffer - 1) != '\n')) {
        ret[i] = buffer[0];
        buffer += 1;
        i++;
    }
    ret[i] = '\0';
    if (i != 0 && ret[i - 1] == '\n') {
        ret[i - 1] = '\0';
    } else
        ret = str_cat_dup(gc, ret, get_next_line(fd));
    return (ret);
}