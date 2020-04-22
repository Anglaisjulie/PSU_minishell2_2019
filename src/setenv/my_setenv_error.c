/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_setenv_error.c
*/

#include "fonctions.h"

int setenv_error(shell_t *shell)
{
    int error = 0;

    if (shell->env_shell == NULL)
        return (-1);
    if (shell->nb_command_one > 3) {
        my_printf("setenv: Too many arguments.\n");
        return (1);
    }
    if (shell->command_shell[1][0] >= '0'
        && shell->command_shell[1][0] <= '9') {
        my_printf("setenv: Variable name must begin with a letter.\n");
        return (1);
    }
    else if (shell->command_shell[1] == NULL) {
        print_env(shell);
        return (0);
    }
    error = my_setenv(shell);
    return (error);
}