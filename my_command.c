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
#include "minishell.h"

char *my_getenv(char *name, char **envp);

int my_exit(int *run)
{
    *run = 0;
    if (isatty(STDIN_FILENO))
        my_putstr("exit\n");
    return (1);
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