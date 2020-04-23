/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** exit.c
*/

#include "fonctions.h"

void exit_with_value(shell_t *shell)
{
    int value = 0;

    value = my_atoi(shell->command_shell[1]);
    value %= 256;
    exit (value);

}

int error_exit(shell_t *shell)
{
    for (int i = 1; shell->command_shell[1][i] != '\0'; i++) {
        if ((shell->command_shell[1][0] < '0'
            || shell->command_shell[1][0] > '9')
            && (my_strlen(shell->command_shell[1]) == 1)) {
            my_printf("exit: Expression Syntax.\n");
            return (1);
        }
        if ((shell->command_shell[1][i] < '0'
            || shell->command_shell[1][i] > '9')
            && shell->command_shell[1][0] == '-') {
            my_printf("exit: Badly formed number.\n");
            return (1);
        }
        if ((shell->command_shell[1][i] < '0'
            || shell->command_shell[1][i] > '9')
            && shell->command_shell[1][0] != '-') {
            my_printf("exit: Expression Syntax.\n");
            return (1);
        }
    }
    return (0);
}

int my_exit(shell_t *shell)
{
    if (shell->number > 1 && shell->len_total != shell->nb_command)
        return (0);
    if (shell->nb_command_one == 1)
        exit (0);
    if (shell->nb_command_one == 2) {
        if ((my_strlen(shell->command_shell[1]) == 1)
            && (shell->command_shell[1][0] < '0'
            || shell->command_shell[1][0] > '9')) {
            my_printf("exit: Expression Syntax.\n");
            return (1);
        }
        if (error_exit(shell) == 1)
            return (1);
        exit_with_value(shell);
    }
    return (0);
}