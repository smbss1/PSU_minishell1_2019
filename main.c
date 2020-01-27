/*
** EPITECH PROJECT, 2019
** main
** File description:
** Main Function
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>
#include <dirent.h>
#include <signal.h>
#include "my.h"
#include "get_next_line.h"
#include "debug.h"
#include "garbage.h"
#include "minishell.h"

void sigint(int status)
{
    signal(SIGINT, sigint);
    char buff[100];
    char *cwd = getcwd(buff, 100);
    my_printf("\n%s~$> ", cwd);
}

int main(int ac, char **av, char **envp)
{
    R_DEV_ASSERT(ac == 1, "", return (84));

    on("exit", my_exit, NULL);
    on("cd", NULL, cd);
    signal(SIGINT, sigint);
    update(envp);
    gc_stop(get_garbage());
    return (0);
}