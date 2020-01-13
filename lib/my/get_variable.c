/*
** EPITECH PROJECT, 2019
** get_variable
** File description:
** Get Variable in a Text
*/

#include <stdlib.h>
#include "my.h"

char *get_variable_name(char *str, char *word)
{
    char delim[] = " :\n";
    char *var;
    char *dup = my_strdup(str);

    var = my_strtok(dup, delim);

    while (var != NULL) {
        if (my_strcmp(var, word) == 0) {
            return (var);
            break;
        }
        var = my_strtok(NULL, delim);
    }
    free (dup);
    return (NULL);
}

char *get_str(char *str, char *word)
{
    char delim[] = ", :\n";
    char *var;
    char *dup = my_strdup(str);

    var = my_strtok(dup, delim);

    while (var != NULL) {
        if (my_strcmp(var, word) == 0) {
            var = my_strtok(NULL, delim);
            return (var);
        }
        var = my_strtok(NULL, delim);
    }
    free (dup);
    return (NULL);
}

int get_number(char *str, char *word)
{
    char delim[] = ", :\n";
    char *var;
    char *dup = my_strdup(str);

    var = my_strtok(dup, delim);

    while (var != NULL) {
        if (my_strcmp(var, word) == 0) {
            var = my_strtok(NULL, delim);
            my_printf("We find the value of %s is %s\n", word, var);
            return (my_getnbr(var));
        }
        var = my_strtok(NULL, delim);
    }
    free (dup);
    return (0);
}