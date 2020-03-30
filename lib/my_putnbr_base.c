/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_putnbr_base.c
*/

#include "lib.h"

int my_putnbr_base(int nbr, char const *base)
{
    int size = my_strlen(base);

    if (nbr < 0) {
        nbr = nbr * -1;
        my_putchar('-');
    } else if (nbr == 0)
        return (0);
    else {
        my_putnbr_base(nbr / size, base);
        my_putchar(base[nbr % size]);
    }
    return (0);
}