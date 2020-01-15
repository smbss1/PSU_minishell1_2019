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

void redirection(char **argv)
{
    for (int i = 0; argv[i]; i++) {
        if (my_strcmp(argv[i], ">") == 0) {
            int fd = open(argv[++i], O_WRONLY | O_CREAT | O_TRUNC | O_CREAT,
                S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
            if (fd == -1)
                return;
            dup2(fd, 1);
            argv[i - 1] = NULL;
            close(fd);
        }
        if (my_strcmp(argv[i], "<") == 0 && argv[2]) {
            int fd = open(argv[++i], O_RDONLY);
            if (fd == -1)
                return;
            dup2(fd, 0);
            argv[i - 1] = NULL;
            close(fd);
        }
    }
}

void execute(char **argv, char **env)
{
    int parent_pid = getpid();
    pid_t child_pid;
    int status;

    parent_pid = fork();
    if (parent_pid < 0)
        my_printf("*** ERROR: forking child process failed\n");
    else if (parent_pid == 0) {
        redirection(argv);
        if (execve(argv[0], argv, env) < 0)
            my_printf("*** ERROR: exec failed\n");
    } else {
        waitpid(parent_pid, &status, 0);
        if (WTERMSIG(status)) {
            my_putstr(strsignal(WTERMSIG(status)));
            my_putstr("\n");
        }
    }
}