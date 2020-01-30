/*
** EPITECH PROJECT, 2019
** my_str_clean
** File description:
** clean a string
*/

void my_str_clean(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '\t') {
            str[i] = ' ';
        }
    }
}