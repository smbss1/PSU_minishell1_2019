/*
** EPITECH PROJECT, 2019
** my_command
** File description:
** command
*/

void my_exit(int *run)
{
    *run = 0;
}

void cd(char *path)
{
    if (chdir(path) < 0)
        perror(path);
}