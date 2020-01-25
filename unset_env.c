/*
** EPITECH PROJECT, 2019
** unset_env
** File description:
** unset env variable
*/

#include <stdlib.h>
#include "debug.h"
#include "my.h"
#include "garbage.h"

static int get_row_length(char const **env)
{
    int row = 0;
    for (int i = 0; env[i]; i++) {
        row++;
    }
    return (row);
}

static int get_col_length(char const **env)
{
    int col = 0;
    for (int i = 0; env[i]; i++) {
        int len = my_strlen(env[i]);
        if (len > col)
            col = len;
    }
    return (col);
}

char **rearrange(char const **env, int i)
{
    int row = get_row_length(env);
    int col = get_col_length(env);
    gc_free(get_garbage(), env[i]);
    env[i] = NULL;
    char **new_env = mem_alloc_2d_array(row, col);
    my_memset_array(new_env, 0, row, col);

    for (int i = 0, j = 0; i < row - 1; i++, j++) {
        if (env[j] != NULL) {
            my_strcpy(new_env[i], env[j]);
        } else
            my_strcpy(new_env[i], env[++j]);
    }
    free_2d_array(env);
    new_env[row - 1] = NULL;
    return (new_env);
}

void unset_env_cmd(char *name, char ***env)
{
    R_DEV_ASSERT(*env && *env[0], "", return);
    R_DEV_ASSERT(name, "", return);
    int i = 0;
    char **new_env = *env;
    while (new_env != NULL && new_env[i]) {
        if (my_strncmp(new_env[i], name, my_strlen(name)) == 0) {
            *env = rearrange(new_env, i);
            return;
        }
        i++;
    }
}