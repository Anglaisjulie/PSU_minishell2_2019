/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_setenv_error.c
*/

#include "fonctions.h"

int check_char(shell_t *shell)
{
    for (int i = 0; i != my_strlen(shell->command_shell[1]); i++) {
        if ((shell->command_shell[1][i] < 'a'
            || shell->command_shell[1][i] > 'z')
            && (shell->command_shell[1][i] < 'A'
            || shell->command_shell[1][i] > 'Z')
            && (shell->command_shell[1][i] < '0'
            || shell->command_shell[1][i] > '9')
            && (shell->command_shell[1][i] != '_')) {
            my_printf
            ("setenv: Variable name must contain alphanumeric characters.\n");
            return (1);
        }
    }
    return (0);
}

int check_first_char(shell_t *shell)
{
    if ((shell->command_shell[1][0] < 'a'
        || shell->command_shell[1][0] > 'z')
        && (shell->command_shell[1][0] < 'A'
        || shell->command_shell[1][0] > 'Z')
        && (shell->command_shell[1][0] != '_')) {
        my_printf("setenv: Variable name must begin with a letter.\n");
        return (1);
    }
    else if (shell->command_shell[1] == NULL) {
        print_env(shell);
        return (0);
    }
    return (0);
}

int setenv_error(shell_t *shell)
{
    int error = 0;

    if (shell->env_shell == NULL)
        return (-1);
    if (shell->nb_command_one > 3) {
        my_printf("setenv: Too many arguments.\n");
        return (1);
    }
    if (check_first_char(shell) == 1)
        return (1);
    if (check_char(shell) == 1)
        return (1);
    error = my_setenv(shell);
    return (error);
}

int stock_name(shell_t *shell, int i, int len)
{
    for (; shell->env_shell[i] != NULL; i++) {
        if (my_strncmp(shell->env_shell[i], shell->command_shell[1], len)
                                                                == 0) {
            if (malloc_stock_name(shell, i) == -1)
                return (-1);
            return (0);
        }
    }
    return (0);
}