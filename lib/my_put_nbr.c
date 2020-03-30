/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** my_put_nbr.c
*/

#include "lib.h"

int my_put_nbr(int nbr)
{
    if (nbr < 0) {
        nbr = nbr * (-1);
        my_putchar('-');
    }
    if (nbr >= 10) {
        my_put_nbr(nbr / 10);
        my_put_nbr(nbr % 10);
    } else {
        my_putchar(nbr + '0');
    }
    return (0);
}