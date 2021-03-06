/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_str_to_word_array.c
*/

#include "fonctions.h"

int nb_word(shell_t *shell, char *command)
{
    int len = -1;

    for (int k = 0; command[k] != '\0'; k++) {
        if ((command[k] == ' ' || command[k] == '\t' || command[k] == '\\'
            || command[k] == '\n')) {
        } else if ((command[k] != ' ' || command[k] != '\t'
            || command[k] != '\\' || command[k] != '\n')
            && (command[k + 1] == ' ' || command[k + 1] == '\t'
            || command[k + 1] == '\n'))
            len++;
    }
    if (len == -1)
        return (FAILURE);
    shell->all_command = malloc(sizeof(char *) * (len + 1));
    if (shell->all_command == NULL)
        return (84);
    shell->all_command[len] = NULL;
    shell->nb_command = len;
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
        if ((command[i] == ' ' || command[i] == '\t' || command[i] == '\\'
            || command[i] == '\n')
            && (command[i + 1] == ' ' || command[i + 1] == '\t'
            || command[i + 1] == '\n')) {
        } else if (command[i] == ' ' || command[i] == '\t'
            || command[i] == '\n') {
            shell->all_command[b] = malloc(sizeof(char) * (a + 1));
            if (shell->all_command[b] == NULL)
                return (84);
            shell->all_command[b][a] = '\0';
            a = 0;
            b++;
        } else
            a++;
    }
    return (0);
}

int malloc_command(shell_t *shell, char *command)
{
    shell->all_command = NULL;
    if (nb_word(shell, command) == 84)
        return (84);
    if (command_malloc(shell, command) == -1)
        return (-1);
    return (0);
}

int my_command_shell(shell_t *shell, char *command)
{
    if (malloc_command(shell, command) == 84)
        return (84);
    add_all_command(shell, command);
    count_command(shell);
    return (0);
}