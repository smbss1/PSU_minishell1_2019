/*
** EPITECH PROJECT, 2019
** test_getnextline
** File description:
** get next line test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include <stdio.h>
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