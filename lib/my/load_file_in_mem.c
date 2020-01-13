/*
** EPITECH PROJECT, 2019
** load_file_in_mem
** File description:
** Load and allocate memory of the file
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"

int sstrlen(char const *filepath)
{
    int fd;
    char c;
    int len;

    fd = fs_open_file(filepath);

    if (fd != -1) {
        while (read(fd, &c, 1) > 0)
            len++;
        close(fd);
    }
    return (len);
}

char *load_file_in_mem(char const *filepath)
{
    int len = sstrlen(filepath);
    char *buffer = malloc(sizeof(char) * len);
    char c;
    int fd;

    fd = fs_open_file(filepath);

    if (fd != -1) {
        while (read(fd, &c, 1) > 0)
            my_charcat(buffer, c);
        close(fd);
    }
    return (buffer);
}