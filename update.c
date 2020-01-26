/*
** EPITECH PROJECT, 2019
** update
** File description:
** up date
*/

#include "my.h"
#include "get_next_line.h"
#include "debug.h"
#include "garbage.h"
#include "minishell.h"

int custom_cmd2(char const **argv, int *run, char ***env)
{
    R_DEV_ASSERT(argv[0], "", return (1));
    if (my_strcmp(argv[0], "env") == 0) {
        env_cmd(*env);
        return (1);
    }
    if (my_strcmp(argv[0], "setenv") == 0) {
        R_DEV_ASSERT(argv[1], "", return (1));
        char buffer[my_strlen(argv[1]) + 1];
        my_sprintf(&buffer, "%s=", argv[1]);
        set_env_cmd(buffer, argv[2], env);
        return (1);
    }
    if (my_strcmp(argv[0], "unsetenv") == 0) {
        R_DEV_ASSERT(argv[1], "", return (1));
        char buffer[my_strlen(argv[1]) + 1];
        my_sprintf(&buffer, "%s=", argv[1]);
        unset_env_cmd(buffer, env);
        return (1);
    }
    return (0);
}

int custom_cmd(char const **argv, int *run, char ***env)
{
    R_DEV_ASSERT(argv[0], "", return (1));
    if (my_strcmp(argv[0], "cd") == 0) {
        emit("cd", argv[1], *env);
        return (1);
    }
    if (my_strcmp(argv[0], "exit") == 0) {
        emit("exit", run, NULL);
        return (1);
    }
    if (my_strcmp(argv[0], "print") == 0) {
        gc_print(get_garbage());
        return (1);
    }
    if (custom_cmd2(argv, run, env) == 1)
        return (1);
    return (0);
}

void treatement(char **argv, char ***envp, int *run)
{
    R_DEV_ASSERT(argv && *envp, "", return);
    if (argv[0][0] == '.' && (argv[0][1] == '/' || argv[0][0] == '/')) {
        execute(argv, *envp);
        return;
    }
    if (custom_cmd(argv, run, envp) == 1)
        return;
    char *path_var = my_getenv("PATH", *envp);
    R_DEV_ASSERT(path_var, "", return);
    my_execvp(argv[0], argv, *envp, path_var);
}

void update(char **envp)
{
    int run = 1;
    char buff[100];
    gc_t *gc = my_gc_new();

    while (run) {
        char *cwd = getcwd(&buff, 100);
        my_printf("%s~$> ", cwd);
        char *line_cmd = get_next_line(0);
        R_DEV_ASSERT(line_cmd, "\n", continue);
        R_DEV_ASSERT(*line_cmd, "", continue);
        char **argv = my_str_to_word_array(line_cmd, " \t");
        treatement(argv, &envp, &run);
        free_2d_array(argv);
        gc_run(gc);
    }
}