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
#include "my.h"
#include "get_next_line.h"
#include "debug.h"
#include "garbage.h"

void my_scanf(const char *fmt, ...);

void on(char *name, void *handler, void *handler2);

int emit(char *name, void *value, void *value2);

void my_exit(int *run);

void cd(char *path);

char *my_getenv(char *name, char **envp);

void my_execvp(char *cmd, char **argv, char **env, char *env_path);

static void launch_child(int parent_id, int child_id, char **args, char **envp)
{
    child_id = fork();
    if (parent_id != getpid())
        if (execve(args[0], args, envp) == -1)
            exit(0);
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

int custom_cmd(char const *str, char *str2, int *run)
{
    R_DEV_ASSERT(str, "", return (1));
    if (my_strcmp(str, "cd") == 0) {
        emit("cd", str2, NULL);
        return (1);
    }
    if (my_strcmp(str, "exit") == 0) {
        emit("exit", run, NULL);
        return (1);
    }
    return (0);
}

void treatement(char **argv, char **envp, int *run)
{
    R_DEV_ASSERT(argv && envp, "", return);
    if (argv[0][0] == '.' && (argv[0][1] == '/' || argv[0][0] == '/')) {
        execute(argv, envp);
        return;
    }
    if (custom_cmd(argv[0], argv[1], run) == 1)
        return;
    char *path_var = my_getenv("PATH", envp);
    R_DEV_ASSERT(path_var, "", return);
    my_execvp(argv[0], argv, envp, path_var);
}

int main(int ac, char **av, char **envp)
{
    tg_start();
    int run = 1;;

    on("exit", my_exit, NULL);
    on("cd", cd, NULL);
    char buff[100];
    while (run) {
        char *cwd = getcwd(&buff, 100);
        my_printf("%s~$> ", cwd);
        char *line_cmd = get_next_line(0);
        char **argv = my_str_to_word_array(line_cmd);
        treatement(argv, envp, &run);
    }
    tg_stop();
    return (0);
}