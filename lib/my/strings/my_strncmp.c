/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** Function that if strings are equals or not
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i;

    for (i = 0; i < n; i++) {
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