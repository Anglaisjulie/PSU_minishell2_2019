/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_str_to_word_array.c
*/

#include "fonctions.h"

int nb_word(shell_t *shell, char *command)
{
    int len = 0;

    for (int k = 0; command[k] != '\0'; k++) {
        if ((command[k] == ' ' || command[k] == '\t')
            && (command[k + 1] == ' ' || command[k + 1] == '\t')) {
        } else if (command[k] == ' ' || command[k] == '\t')
            len++;
    }
    shell->command_shell = malloc(sizeof(char *) * (len + 1));
    shell->command_shell[len] = NULL;
    if (shell->command_shell == NULL)
        return (84);
    shell->command_shell[len] = NULL;
    return (0);
}

int next_spaces(char *command)
{
    int spaces = 0;

    for (int i = 0; command[i] == ' ' || command[i] == '\t'
                                                || command[i] == '\n'; i++)
        spaces++;
    return (spaces);
}

int command_malloc(shell_t *shell, char *command)
{
    int a = 0;
    int b = 0;

    for (int i = next_spaces(command); command[i] != '\0'; i++) {
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
    return (0);
}

int malloc_command(shell_t *shell, char *command)
{
    shell->command_shell = NULL;
    if (nb_word(shell, command) == 84)
        return (84);
    if (command_malloc(shell, command) == -1)
        return (-1);
    return (0);
}

int my_command_shell(shell_t *shell, char *command)
{
    int i = 0;
    int a = 0;

    if (malloc_command(shell, command) == 84)
        return (84);
    for (int j = next_spaces(command); command[j] != '\0'; j++) {
        if ((command[j] == ' ' || command[j] == '\t' || command[j] == '\n')
            && (command[j + 1] == ' ' || command[j + 1] == '\t'
            || command[j + 1] == '\n')) {
        } else if (command[j] == ' ' || command[j] == '\t'
            || command[j] == '\n') {
            a = 0;
            i++;
        } else {
            shell->command_shell[i][a] = command[j];
            a++;
        }
    }
    return (0);
}