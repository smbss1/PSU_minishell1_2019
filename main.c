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

void my_scanf(const char *fmt, ...);

void on(char *name, void *handler, void *handler2);

void my_exit(int *run);

void cd(char *path);

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

void execute(char **argv, char **env)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid < 0)
        my_printf("*** ERROR: forking child process failed\n");
    else if (pid == 0) {
        if (execve(argv[0], argv, env) < 0)
            my_printf("*** ERROR: exec failed\n");
    } else
        while (wait(&status) != pid);
}

int custom_cmd(char *str, char *str2, int *run)
{
    if (my_strcmp(str, "cd") == 0) {
        emit("cd", str2, NULL);
        return (1);
    }
    if (my_strcmp(str, "exit") == 0) {
        emit(str, run, NULL);
        return (1);
    }
    return (0);
}

void treatement(char **argv, char **envp, int *run)
{
    if (argv[0][0] == '.' && argv[0][1] == '/' || argv[0][0] == '/') {
        execute(argv, envp);
        return;
    }
    custom_cmd(argv[0], argv[1], run);
    for (int i = 0; envp[i]; i++) {
        char *test = my_strdup(envp[i]);
        char *env_word = my_strtok(test, "=");
        if (my_strcmp(env_word, "PATH") == 0)
            my_execvp(argv[0], argv, envp, envp[i]);
        // free(test);
    }
}

int main(int ac, char **av, char **envp)
{
    int run = 1;

    on("exit", my_exit, NULL);
    on("cd", cd, NULL);
    while (run) {
        my_printf("$>");
        char *line_cmd = get_next_line(0);
        char **argv = my_str_to_word_array(line_cmd);
        treatement(argv, envp, &run);
    }
    return (0);
}