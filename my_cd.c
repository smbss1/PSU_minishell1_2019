/*
** EPITECH PROJECT, 2019
** my_cd
** File description:
** cd cmd
*/

#include <stdlib.h>
#include <sys/stat.h>
#include "debug.h"
#include "minishell.h"
#include "my.h"

void error_handle(char *path)
{
    struct stat stats;
    if (stat(path, &stats) == 0 && !S_ISDIR(stats.st_mode))
        my_printf("%s: Not a directory.\n", path);
    else
        my_printf("%s: No such file or directory.\n", path);
}

char *save_oldpwd(char *oldpwd)
{
    static char *old;
    if (oldpwd != NULL)
        old = oldpwd;
    else
        return (old);
    return (NULL);
}

void cd(char *path, char ***env)
{
    if (path == NULL)
        path = my_strdup("~");
    save_oldpwd(my_getenv("PWD", *env));
    if (my_strcmp(path, "-") == 0) {
        path = my_getenv("PWD", *env);
        R_DEV_ASSERT(path, ": No such file or directory.\n", return);
        path = my_strtok(my_strdup(path), ": = ");
    }
    if (my_strcmp(path, "~") == 0) {
        path = my_getenv("HOME", *env);
        R_DEV_ASSERT(path, ": No such file or directory.\n", return);
        path = my_strtok(my_strdup(path), ": = ");
    }
    if (chdir(path) != -1) {
        set_env_cmd("OLDPWD", save_oldpwd(NULL), env);
        set_env_cmd("PWD", path, env);
        gc_free(get_garbage(), path);
        return;
    }
    error_handle(path);
}