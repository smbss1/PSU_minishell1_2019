/*
** EPITECH PROJECT, 2019
** my_sort_int_array
** File description:
** Function that sort int in ascending order
*/

#include "../../include/my.h"

void my_sort_int_array(int *tab, int size)
{
    int tmp = 0;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (tab[j] < tab[i]) {
                tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
        }
    }
}