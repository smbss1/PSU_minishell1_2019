/*
** EPITECH PROJECT, 2019
** load_2d_arr_from_file
** File description:
** Load 2D array to file content
*/

/**
* \file load_2d_arr_from_file.c
* \author BESSEAU Samuel
* \version 1
* \date November 24th
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

/**
* \brief This function create a 2d array of char and
*  return this array with the characters read in the file
* \param filepath : This is the pointer to the name file.
* \param nb_rows : This is the nbr of rows that will be allocated for the array
* \param nb_cols : This is the nbr of cols that will be allocated for the array
* \return A new 2d array that contains the characters read in the file.
*/

char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols)
{
    char **map = mem_alloc_2d_array(nb_rows, nb_cols);
    int fd = fs_open_file(filepath);
    char my_line[nb_cols];

    fs_get(my_line, 10, fd);
    for (int i = 0; i < nb_rows; i++) {
        fs_get(my_line, nb_cols, fd);
        my_strcpy(map[i], my_line);
    }
    return (map);
}