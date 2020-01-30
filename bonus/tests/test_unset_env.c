/*
** EPITECH PROJECT, 2019
** unsetenv
** File description:
** un set env test function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include "minishell.h"
#include "my.h"

static void redirect_all_stdout(void)
{
    gc_t *gc = my_gc_new();
    cr_redirect_stdout();
    cr_redirect_stderr();
}

static void finish(void)
{
    gc_stop(get_garbage());
}

Test(unsetenv , unset_path_env, .init = redirect_all_stdout, .fini = finish)
{
    char **env = mem_alloc_2d_array(4, 12);
    env[0] = "PATH=/bin:/test/unit";
    env[1] = "GDM=/test/unit";
    env[2] = "TEK=5484894";
    env[3] = NULL;
    unset_env_cmd("GDM=", &env);
    cr_assert(my_strcmp(env[1], "TEK=5484894") == 0);
    free_2d_array((void **) env);
}