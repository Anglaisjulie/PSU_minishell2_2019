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
    error = option_shell(shell);
    if (error == NO)
        error = all_fonctions(shell);
    return (error);
}