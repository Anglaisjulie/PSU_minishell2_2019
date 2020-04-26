/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** semicolon.c
*/

#include "fonctions.h"

void new_command(shell_t *shell, int start, int end)
{
    int count = 0;
    int x = 0;

    if (start != 0 && shell->nb_command == shell->len_total)
        end += 1;
    for (int i = start; i != end; i++) {
        count++;
        shell->command_shell[x] = shell->all_command[i];
        x++;
    }
    shell->nb_command_one = count;
    shell->tour++;
    if (shell->all_command[shell->index_command][0] == ';'
        || shell->all_command[shell->index_command][0] == '|')
        shell->index_command++;
}

int exe_semicolon(shell_t *shell, int start, int end)
{
    int error = 0;

    new_command(shell, start, end);
    if (shell->command_shell[0] == NULL || shell->command_shell[0][0] == '\0')
        return (0);
    error = option_shell(shell);
    if (error == NO) {
        my_path_env(shell);
        error = all_fonctions(shell);
    }
    return (error);
}

int option_redirect(shell_t *shell, int start, int error)
{
    if (shell->type_command == SEMICOLON) {
        error = exe_semicolon(shell, start, shell->index_command);
    }
    if (shell->type_command == PIPE && shell->tour == 0) {
        new_command(shell, start, shell->index_command);
        shell->command_one = shell->command_shell;
        return (0);
    }
    if (shell->type_command == PIPE && shell->tour == 1) {
        if (shell->nb_command < 2) {
            my_printf("Invalid null command.\n");
            return (1);
        }
        new_command(shell, start, shell->index_command);
        shell->command_two = shell->command_shell;
        error = exe_pipe(shell, start, shell->index_command);
    }
    return (error);
}