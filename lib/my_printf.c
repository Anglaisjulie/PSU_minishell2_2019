/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** my_printf.c
*/

#include "lib.h"

void flags(va_list ap, char *str, int i)
{
    flags_b_p(ap, i, str);
    flags_int(ap, i, str);
    flags_char(ap, i, str);
}

int my_printf(char *str, ...)
{
    va_list ap;
    va_start(ap, str);
    int a = 0;

    if (str == 0)
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%') {
            flags(ap, str, i);
            a += 2;
            i++;
        } else {
            my_putchar(str[a]);
            a++;
        }
    }
    va_end(ap);
    return (0);
}