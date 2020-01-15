/*
** EPITECH PROJECT, 2019
** getenv
** File description:
** get var env
*/

#include <stdlib.h>

char *my_getenv(char *name, char **envp)
{
    for (int i = 0; envp[i]; i++) {
        char *test = my_strdup(envp[i]);
        char *env_word = my_strtok(test, "=");
        if (my_strcmp(env_word, name) == 0)
            return (envp[i]);
    }
    return (NULL);
}