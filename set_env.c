/*
** EPITECH PROJECT, 2019
** set_env
** File description:
** set env
*/

#include <stdlib.h>
#include "debug.h"
#include "my.h"
#include "garbage.h"
#include "minishell.h"

static int get_col_length(char **env)
{
    int col = 0;
    for (int i = 0; env[i]; i++) {
        int len = my_strlen(env[i]);
        if (len > col)
            col = len;
    }
    return (col);
}

static char *new_line(char const *name, char const *path)
{
    char *new_line = NULL;

    new_line = gc_malloc(get_garbage(), sizeof(char) * (my_strlen(name)
                                                + my_strlen(path) + 1));
    if (new_line == NULL)
        return (NULL);
    new_line = my_strncpy(new_line, name, my_strlen(name));
    new_line = my_strncat(new_line, path, my_strlen(path));
    return (new_line);
}

static char	**add_var(char **env, char *to_change,
                    char *new_value, int env_size)
{
    int col = get_col_length(env);
    int	idx = 0;
    char **new_env = mem_alloc_2d_array(env_size + 2, col);

    my_memset_array(new_env, 0, env_size + 2, col);
    if (new_env == NULL)
        return (env);
    while (env != NULL && env[idx]) {
        my_strcpy(new_env[idx], env[idx]);
        idx++;
    }
    new_env[idx] = new_line(to_change, new_value);
    if (new_env[idx] == NULL)
        return (new_env);
    idx++;
    new_env[idx] = NULL;
    free_2d_array((void **)env);
    return (new_env);
}

void set_env_cmd(char *name, char *path, char ***env)
{
    R_DEV_ASSERT(*env && *env[0], "", return);
    R_DEV_ASSERT(name, "", return);
    R_DEV_ASSERT(path, "", return);
    char *line;
    int i = 0;
    char **new_env = *env;

    while (*new_env != NULL && new_env[i]) {
        if (my_strncmp(new_env[i], name, my_strlen(name)) == 0) {
            line = new_line(new_env[i], my_strcat_dup(":", path));
            R_DEV_ASSERT(line, "", return);
            gc_free(get_garbage(), new_env[i]);
            new_env[i] = my_strdup(line);
            gc_free(get_garbage(), line);
            return;
        }
        i++;
    }
    *env = add_var(new_env, name, path, i);
}