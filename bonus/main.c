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

int custom_cmd(char const *str, char *str2, int *run, char **env)
{
    R_DEV_ASSERT(str, "", return (1));
    if (my_strcmp(str, "cd") == 0) {
        emit("cd", str2, env);
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
    if (custom_cmd(argv[0], argv[1], run, envp) == 1)
        return;
    char *path_var = my_getenv("PATH", envp);
    R_DEV_ASSERT(path_var, "", return);
    my_execvp(argv[0], argv, envp, path_var);
}

__sighandler_t sigint(int status)
{
    signal(SIGINT, sigint);
}

int main(int ac, char **av, char **envp)
{
    int run = 1;
    char buff[100];

    tg_start();
    on("exit", my_exit, NULL);
    on("cd", NULL, cd);
    signal(SIGINT, sigint);
    while (run) {
        char *cwd = getcwd(&buff, 100);
        my_printf("%s~$> ", cwd);
        char *line_cmd = get_next_line(0);
        R_DEV_ASSERT(line_cmd, "\n", continue);
        char **argv = my_str_to_word_array(line_cmd);
        treatement(argv, envp, &run);
    }
    tg_stop();
    return (0);
}