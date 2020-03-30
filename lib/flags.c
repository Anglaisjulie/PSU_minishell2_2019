/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** flags.c
*/

#include "lib.h"

int flags_b_p(va_list ap, int i, char *str)
{
    switch (str[i + 1])
    {
        case 'o':
            my_putnbr_base(va_arg(ap, unsigned int), "01234567");
            break;
        case 'x':
            my_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
            break;
        case 'X':
            my_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
            break;
        case 'b':
            my_putnbr_base(va_arg(ap, unsigned int), "01");
            break;
        default:
            return (0);
    }
    return (0);
}

int flags_int(va_list ap, int i, char *str)
{
    switch (str[i + 1])
    {
        case 'd':
            my_put_nbr(va_arg(ap, int));
            break;
        case 'i':
            my_put_nbr(va_arg(ap, int));
            break;
        case 'u':
            my_put_unsigned_nbr(va_arg(ap, unsigned int));
            break;
        default:
            return (0);
    }
    return (0);
}

int flags_char(va_list ap, int i, char *str)
{
    switch (str[i + 1])
    {
        case 'c':
            my_putchar(va_arg(ap, int));
            break;
        case 's':
            my_putstr(va_arg(ap, char *));
            break;
        case 'C':
            my_putchar(va_arg(ap, int) - 32);
            break;
        case '%':
            my_putchar('%');
            break;
        default:
            return (0);
    }
    return (0);
}
