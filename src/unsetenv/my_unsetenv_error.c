/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_unsetenv_error.c
*/

#include "fonctions.h"

int unsetenv_error(shell_t *shell)
{
    if (shell->env_shell == NULL)
        return (-1);
    else if (shell->nb_command_one == 3) {
        my_printf("unsetenv: Too few arguments.\n");
        return (-1);
    } else if (my_unsetenv(shell) == - 1)
        return (-1);
    return (0);
}