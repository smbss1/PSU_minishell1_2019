/*
** EPITECH PROJECT, 2019
** my_command
** File description:
** command
*/

#include <stdlib.h>
#include "my.h"

char *my_getenv(char *name, char **envp);

void my_exit(int *run)
{
    *run = 0;
    my_putstr("exit\n");
}

void cd(char *path, char **env)
{
    if (my_strcmp(path, "-") == 0) {
        path = my_getenv("PWD", env);
        my_strtok(my_strdup(path), "=");
        path = my_strtok(NULL, ":");
    }
    if (my_strcmp(path, "~") == 0) {
        path = my_getenv("HOME", env);
        my_strtok(my_strdup(path), "=");
        path = my_strtok(NULL, ":");
    }
    if (path && chdir(path) < 0)
        perror(path);
}