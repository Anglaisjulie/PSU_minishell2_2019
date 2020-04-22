/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** main.c
*/

#include "fonctions.h"

int main(int ac, char **av, char **env)
{
    shell_t shell = {0};
    (void) av;

    if (ac != 1)
        return (84);
    if (my_cpy_env(&shell, env) == 84)
        return (84);
    if (my_sh(&shell) == 1) {
        return (1);
    } else
        return (0);
}