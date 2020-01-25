/*
** EPITECH PROJECT, 2019
** execut
** File description:
** execute a cmd
*/

#include<sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "garbage.h"
#include "my.h"

void execute(char **argv, char **env)
{
    int parent_pid = getpid();
    int status;

    parent_pid = fork();
    if (parent_pid < 0)
        my_putstr("*** ERROR: forking child process failed\n");
    else if (parent_pid == 0) {
        if (execve(argv[0], argv, env) < 0)
            my_putstr("*** ERROR: exec failed\n");
    } else {
        waitpid(parent_pid, &status, 0);
        if (WTERMSIG(status)) {
            my_putstr(strsignal(WTERMSIG(status)));
            my_putstr("\n");
        }
    }
}