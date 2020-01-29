/*
** EPITECH PROJECT, 2019
** test_getnextline
** File description:
** get next line test
*/

#include <criterion/criterion.h>
#include  <criterion/redirect.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "minishell.h"
#include "my.h"

void redirect_all_stdout(void)
{
    gc_t *gc = my_gc_new();
    cr_redirect_stdout();
    cr_redirect_stderr();
}

void finish(void)
{
    gc_stop(get_garbage());
}


Test(execute , simple_cmd_full_directory , .init = redirect_all_stdout)
{
    char *argv[] = { "/bin/ls", NULL };
    char *env[] = { NULL };
    execute(argv, env);
    cr_assert_stdout_neq_str("*** ERROR: exec failed\n");
}

Test(execute , simple_exec , .init = redirect_all_stdout)
{
    char *argv[] = { "./tests/simple_exec", NULL };
    char *env[] = { NULL };
    execute(argv, env);
    cr_assert_stdout_eq_str("Hello Wordl !\n");
}

Test(my_execvp , simple_cmd , .init = redirect_all_stdout)
{
    char *argv[] = { "ls", NULL };
    char *env[] = { "PATH=/bin", NULL };
    my_execvp(argv[0], argv, env, env[0]);
    cr_assert_stdout_neq_str("*** ERROR: exec failed\n");
}

Test(getenv , get_path_env , .init = redirect_all_stdout)
{
    char *env[] = { "PATH=/bin", NULL };
    char *variable = my_getenv("PATH", env);
    cr_assert_str_eq("PATH=/bin", variable);
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