/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** Function that copies a string into another
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i;

    for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            if (s1[i] < s2[i]) {
                return (-10);
                break;
            }
            else if (s1[i] > s2[i]) {
                return (10);
                break;
            }
            return (1);
            break;
        }
    }
    return (0);
}