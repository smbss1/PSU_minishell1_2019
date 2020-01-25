/*
** EPITECH PROJECT, 2019
** find_cmd_path
** File description:
** find
*/

#include <dirent.h>
#include <stdlib.h>
#include "my.h"

void find_cmd_path(DIR *directory, char *path, char *cmd, char **path_found)
{
    struct dirent *dirent = NULL;

    dirent = readdir(directory);
    while (dirent) {
        if (my_strcmp(cmd, dirent->d_name) == 0)
            *path_found = path;
        dirent = readdir(directory);
    }
}