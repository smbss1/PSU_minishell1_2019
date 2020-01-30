/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** mini shell.h
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

#include "garbage.h"

void on(char *name, void *handler, void *handler2);
int emit(char *name, void *value, void *value2);
void my_exit(int *run);
void cd(char *path, char ***env);
char *my_getenv(char *name, char **envp);
void my_execvp(char *cmd, char **argv, char **env, char *env_path);
char *str_cat_dup(gc_t *gc, char *str1, char *str2);
void set_env_cmd(char *name, char *path, char ***env);
void execute(char **argv, char **env);
void unset_env_cmd(char *name, char ***env);
void env_cmd(char **env);
void update(char **envp);
void treatement(char **argv, char ***envp, int *run);
int isexecutable (struct stat stats);
void my_str_clean(char *str);

#endif