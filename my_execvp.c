/*
** EPITECH PROJECT, 2019
** my_execvp
** File description:
** execvp
*/

#include <dirent.h>
#include <stdlib.h>

void my_execvp(char *cmd, char **argv, char **env, char *env_path)
{
    DIR *directory = NULL;
    char *path_found = NULL;
    char *env_dup = my_strdup(env_path);
    char *path = my_strtok(env_dup, "=:");

    for (; path; path = my_strtok(NULL, ":")) {
        directory = opendir(path);
        if (directory)
            find_cmd_path(directory, path, cmd, &path_found);
    }
    char c[50];
    my_sprintf(&c, "%s/%s", path_found, cmd);
    argv[0] = c;
    execute(argv, env);
    free(env_dup);
}