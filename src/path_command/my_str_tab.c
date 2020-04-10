/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_str_tab.c
*/

#include "fonctions.h"

int option_command_malloc(shell_t *shell, char *command, int i)
{
    int a = 0;
    int b = 0;

    if ((command[i] == ' ' || command[i] == '\t' || command[i] == '\n')
        && (command[i + 1] == ' ' || command[i + 1] == '\t'
        || command[i + 1] == '\n')) {
    } else if (command[i] == ' ' || command[i] == '\t'
        || command[i] == '\n') {
        shell->command_shell[b] = malloc(sizeof(char) * (a + 1));
        if (shell->command_shell[b] == NULL)
            return (84);
        shell->command_shell[b][a] = '\0';
        a = 0;
        b++;
    } else
        a++;
}

int command_malloc(shell_t *shell, char *command)
{
    for (int i = next_spaces(command); command[i] != '\0'; i++) {
        option_command_malloc(shell, command, i);
    }
    return (0);
}