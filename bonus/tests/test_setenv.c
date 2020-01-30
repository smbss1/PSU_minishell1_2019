/*
** EPITECH PROJECT, 2019
** test_setenv
** File description:
** test set env
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
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

Test(setenv , add_path_env, .init = redirect_all_stdout, .fini = finish)
{
    char **env = mem_alloc_2d_array(2, 10);
    my_strcpy(env[0], "PATH=/bin");
    env[1] = NULL;
    set_env_cmd("PATH", "/salut", &env);
    cr_assert_str_eq(env[0], "PATH=/bin:/salut");
    free_2d_array((void **) env);
}

Test(setenv , set_new_path_env, .init = redirect_all_stdout, .fini = finish)
{
    char **env = mem_alloc_2d_array(2, 12);
    env[0] = "Pfsv=veve";
    env[1] = NULL;
    set_env_cmd("PATH=", "/salut", &env);
    cr_assert(my_strcmp(env[1], "PATH=/salut") == 0);
    free_2d_array((void **) env);
}