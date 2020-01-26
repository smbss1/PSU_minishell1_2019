/*
** EPITECH PROJECT, 2019
** debug
** File description:
** Debug Function
*/

#ifndef _DEBUG_
#define _DEBUG_
#include <stdio.h>
void debug(char *format);
#define R_DEV_ASSERT(cond, fmt, ret) \
    if (!(cond)) debug(fmt); \
    if (!(cond)) ret;
#endif