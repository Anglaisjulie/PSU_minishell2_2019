/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** separate_command.c
*/

#include "fonctions.h"

int option_separator(shell_t *shell)
{
    if (shell->nb_command == shell->len_total) {
        return (1);
    } else if (shell->all_command[shell->index_command][0] == ';') {
        return (1);
    }
    return (0);
}

int size_command_exe(shell_t *shell)
{
    int start = shell->index_command;
    shell->len_total = start;

    for (; option_separator(shell) != 1; shell->index_command++) {
        shell->len_total++;
    }
    return (start);
}

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
    if (shell->all_command[shell->index_command][0] == ';')
        shell->index_command++;
}

int malloc_one_command(shell_t *shell)
{
    int a = 0;
    int x = 0;
    int start = 0;

    start = size_command_exe(shell);
    shell->command_shell = malloc(sizeof(char *) * (shell->index_command + 1));
    if (shell->command_shell == NULL)
        return (FAILURE);
    shell->command_shell[shell->index_command] = NULL;
    for (int i = 0; i != shell->index_command; i++) {
        a = my_strlen(shell->all_command[shell->index_command]);
        shell->command_shell[i] = malloc(sizeof(char) * (a + 1));
        if (shell->command_shell[i] == NULL)
            return (FAILURE);
        shell->command_shell[i][a] = '\0';
    }
    //if (shell->type_command == SEMICOLON)
        new_command(shell, start, shell->index_command);
    return (0);
}

int separator_shell(shell_t *shell)
{
    if (shell->number == 1) {
        shell->command_shell = shell->all_command;
        shell->nb_command_one = shell->nb_command + 1;
        return (0);
    }
    malloc_one_command(shell);
    return (0);
}