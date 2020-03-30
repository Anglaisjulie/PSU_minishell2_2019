/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_strcpy
*/

#include "lib.h"

char *my_strcpy(char *dest, char const *src)
{
    for (int i = 0; i < my_strlen(src); i++) {
        dest[i] = src[i];
    }
    dest[my_strlen(src)] = '\0';
    return (dest);
}
