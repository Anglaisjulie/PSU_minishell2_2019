/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** my_putstr.c
*/

#include "lib.h"

int my_putstr(char *str)
{
    int i = 0;

    if (str == 0)
        return (0);
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}