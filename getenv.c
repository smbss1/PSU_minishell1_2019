/*
** EPITECH PROJECT, 2019
** getenv
** File description:
** get var env
*/

#include <stdlib.h>
#include "garbage.h"
#include "my.h"

char *my_getenv(char *name, char **envp)
{
    if (name == NULL || envp == NULL || envp[0] == NULL)
        return (NULL);
    for (int i = 0; envp[i]; i++) {
        char *test = my_strdup(envp[i]);
        char *env_word = my_strtok(test, "=");
        if (my_strcmp(env_word, name) == 0)
            return (envp[i]);
        gc_free(get_garbage(), test);
    }
    return (NULL);
}