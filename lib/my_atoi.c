/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** my_atoi.c
*/

#include "lib.h"

int	my_atoi(char *str)
{
    int nb = 0;
    int nega = 1;
    int i = 0;
    int result = 0;

    while (str[i] <= ' ')
        i++;
    if (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
        {
            nega *= -1;
        }
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10 + (str[i] - 48);
        i++;
    }
    result = nb * nega;
    return (result);
}