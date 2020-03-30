/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_strcmp
*/

#include "lib.h"

int my_strcmp(char const *s1, char const *s2)
{
    int n1 = 0;
    int n2 = 0;

    for (int i = 0; s1[i]; i++)
        n1 += s1[i];

    for (int j = 0; s2[j]; j++)
        n2 += s2[j];

    if (n1 == n2)
        return (0);
    else if (n1 < n2)
        return (-1);
    else
        return (1);
}
