/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** add_all_command.c
*/

#include "fonctions.h"

void add_loop(shell_t *shell, char *command, int a, int i)
{
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
}

void add_all_command(shell_t *shell, char *command)
{
    int i = 0;
    int a = 0;

    add_loop(shell, command, a, i);
    if (shell->all_command[0][0] == '|')
        shell->nb_command--;
}

int location_of_path(shell_t *shell, int location)
{
    for (int i = 0; shell->env_shell[i] != NULL; i++) {
        if (my_strncmp(shell->env_shell[i], "PATH=", 5) == 0) {
            location = i;
            break;
        }
    }
    return (location);
}