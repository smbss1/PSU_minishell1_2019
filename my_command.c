/*
** EPITECH PROJECT, 2019
** my_command
** File description:
** command
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include "debug.h"
#include "garbage.h"

char *my_getenv(char *name, char **envp);

void my_exit(int *run)
{
    *run = 0;
    my_putstr("exit\n");
}

void cd(char *path, char **env)
{
    if (path == NULL)
        path = my_strdup("~");
    if (my_strcmp(path, "-") == 0) {
        path = my_getenv("PWD", env);
        R_DEV_ASSERT(path, "", return);
        my_strtok(my_strdup(path), " = ");
        path = my_strtok(NULL, ":");
    }
    if (my_strcmp(path, "~") == 0) {
        path = my_getenv("HOME", env);
        R_DEV_ASSERT(path, "", return);
        my_strtok(my_strdup(path), " = ");
        path = my_strtok(NULL, ":");
    }
    if (chdir(path) < 0)
        perror(path);
    gc_free(get_garbage(), path);
}

void env_cmd(char **env)
{
    R_DEV_ASSERT(env, "", return);
    R_DEV_ASSERT(env[0], "", return);
    for (int i = 0; env[i]; i++) {
        my_putstr(env[i]);
        my_putstr("\n");
    }
}