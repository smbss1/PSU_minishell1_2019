/*
** EPITECH PROJECT, 2019
** execut
** File description:
** execute a cmd
*/

#include<sys/wait.h>

void execute(char **argv, char **env)
{
    int parent_pid = getpid();
    pid_t child_pid;
    int status;

    parent_pid = fork();
    if (parent_pid < 0)
        my_printf("*** ERROR: forking child process failed\n");
    else if (parent_pid == 0) {
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