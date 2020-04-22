/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_setenv_error.c
*/

#include "fonctions.h"

int setenv_error(shell_t *shell)
{
    if (shell->env_shell == NULL)
        return (-1);
    if (shell->nb_command_one > 3) {
        my_printf("setenv: Too many arguments.\n");
        return (-1);
    }
    else if (shell->command_shell[1] == NULL) {
        print_env(shell);
        return (0);
    } else if (my_setenv(shell) == - 1)
        return (-1);
    return (0);
}