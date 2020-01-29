/*
** EPITECH PROJECT, 2019
** my_execvp
** File description:
** execvp
*/

#include <sys/stat.h>
#include <stdlib.h>
#include "my.h"
#include "garbage.h"
#include "minishell.h"

void execute(char **argv, char **env);

void my_execvp(char *cmd, char **argv, char **env, char *env_path)
{
    struct stat stats = {0};
    char *env_dup = my_strdup(env_path), *path_found = NULL;
    char *path = my_strtok(env_dup, " = "), *new_path = NULL;

    for (; path; path = my_strtok(NULL, ":")) {
        new_path = my_strcat_dup(path, "/");
        gc_free(get_garbage(), new_path);
        new_path = my_strcat_dup(new_path, cmd);
        if (new_path && stat(new_path, &stats) == 0 && stats.st_mode & S_IXUSR
                                                    && S_ISREG(stats.st_mode))
            path_found = my_strdup(new_path);
        gc_free(get_garbage(), new_path);
        gc_free(get_garbage(), path);
    }
    gc_free(get_garbage(), env_dup);
    if (path_found && path_found[0] != '\0') {
        gc_free(get_garbage(), argv[0]);
        argv[0] = path_found;
        execute(argv, env);
    } else
        my_printf("%s: %s%sCommand not found.\n", cmd, BOLD, RED);
}