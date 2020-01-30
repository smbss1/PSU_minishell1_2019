/*
** EPITECH PROJECT, 2019
** test_getenv
** File description:
** test get env funtion
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

Test(getenv , get_path_env , .init = redirect_all_stdout)
{
    char *env[] = { "PATH=/bin", NULL };
    char *variable = my_getenv("PATH", env);
    cr_assert_str_eq(variable, "/bin");
}