/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** main.c
*/

#include "fonctions.h"

int main(int ac, char **av, char **env)
{
    shell_t *shell = NULL;
    (void) av;

    shell = malloc(sizeof(shell_t));
    if (ac != 1)
        return (84);
    if (my_cpy_env(shell, env) == 84)
        return (84);
    my_sh(shell);
    return (0);
}