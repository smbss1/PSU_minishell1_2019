/*
** EPITECH PROJECT, 2019
** fs_get
** File description:
** Nothing
*/

/**
* @file fs_get.c
* \author BESSEAU Samuel
* \version 1
* \date November 24th
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char *fs_get(char my_string[], int bytes, int fd)
{
    int c, i = 0;

    if (bytes <= 0)
        return my_string;
    while (i < bytes && read(fd, &c, 1) > 0) {
        if ((char)c == '\n')
            break;
        my_string[i] = c;
        i++;
    }
    if ((char)c == '\n')
        read(fd, &c, 1);
    my_string[i] = '\0';

    if (i > 0)
        return my_string;
    else
        return NULL;
}