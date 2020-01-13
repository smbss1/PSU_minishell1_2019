/*
** EPITECH PROJECT, 2019
** fs_open_file
** File description:
** Return value
*/

#include <unistd.h>
#include "my.h"
#include <fcntl.h>

int fs_open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd != -1)
        return (fd);
    else
        return (-1);
}