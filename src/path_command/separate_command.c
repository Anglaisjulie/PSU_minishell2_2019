/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** separate_command.c
*/

#include "fonctions.h"

int separator_check(shell_t *shell)
{
    switch (shell->all_command[shell->index_command][0])
    {
    case ';':
        shell->type_command = SEMICOLON;
        return (1);
    case '|':
        shell->type_command = PIPE;
        return (1);
    }
    return (0);
}

int option_separator(shell_t *shell)
{
    if (shell->nb_command == shell->len_total) {
        return (1);
    } else if (separator_check(shell) == 1)
        return (1);
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

int malloc_one_command(shell_t *shell)
{
    int a = 0;
    int start = 0;
    int error = 0;

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
            printf("Invalid null command.\n");
            return (1);
        }
        new_command(shell, start, shell->index_command);
        shell->command_two = shell->command_shell;
        error = exe_pipe(shell, start, shell->index_command);
    }

    return (error);
}

int separator_shell(shell_t *shell)
{
    int error = 0;

    if (shell->number == 1) {
        for (int i = 0; i != shell->nb_command + 1; i++)
            if ((shell->all_command[i][0] == '|')) {
                printf("Invalid null command.\n");
                return (1);
            }
        shell->command_shell = shell->all_command;
        shell->nb_command_one = shell->nb_command + 1;
        int error = 0;
        error = option_shell(shell);
        if (error == NO)
            error = all_fonctions(shell);
        return (error);
    }
    error = malloc_one_command(shell);
    return (error);
}