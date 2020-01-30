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
        char *new_name = my_strcat_dup(name, "=");
        gc_free(get_garbage(), new_name);
        if (my_strncmp(envp[i], new_name, my_strlen(new_name)) == 0)
            return (envp[i] + my_strlen(new_name));
    }
    return (NULL);
}