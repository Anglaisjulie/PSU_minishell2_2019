/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** add_all_command.c
*/

#include "fonctions.h"

void add_all_command(shell_t *shell, char *command)
{
    int i = 0;
    int a = 0;

    for (int j = next_spaces(command); command[j] != '\0'; j++) {
        if (((command[j] == ' ' || command[j] == '\t'
            || command[j] == '\\' || command[j] == '\n')
            && (command[j + 1] == ' ' || command[j + 1] == '\t'
            || command[j + 1] == '\n'))
            || command[j] == '\\') {
        } else if (command[j] == ' ' || command[j] == '\t'
            || command[j] == '\n') {
            a = 0;
            i++;
        } else {
            shell->all_command[i][a] = command[j];
            if (shell->all_command[i][0] == ';'
                                        && shell->all_command[i + 1] == NULL)
                shell->nb_command--;
            a++;
        }
    }
    if (shell->all_command[0][0] == '|')
        shell->nb_command--;
}