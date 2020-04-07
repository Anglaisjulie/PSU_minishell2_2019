/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_sh.c
*/

#include "fonctions.h"

int my_sh(shell_t *shell)
{
    char *command = NULL;
    size_t size_command = 0;
    int eof = 0;
    int check = 0;

    while (eof != -1) {
        display_prompt();
        if (getline(&command, &size_command, stdin) == -1) {
            exit(-1);
        }
        if (my_strlen(command) != 1 && -1) {
            my_command_shell(shell, command);
            check = option_shell(shell);
            if (check == 1) {
                my_path_env(shell);
                all_fonctions(shell);
            }
        }
    }
    return (0);
}

int option_shell(shell_t *shell)
{
    int a = 0;

    if (my_strcmp(shell->command_shell[0], "env") == 0) {
        if (print_env(shell) == -1)
            return (-1);
        return (0);
    }
    if (my_strcmp(shell->command_shell[0], "exit") == 0) {
        my_printf("exit\n");
        exit(0);
    }
    a = shell_option(shell);
    if (a == -1)
        return (-1);
    else if (a == 1)
        return (1);
    return (0);
}

int shell_option(shell_t *shell)
{
    if (my_strcmp(shell->command_shell[0], "cd") == 0) {
        if (my_cd(shell) == -1)
            return (-1);
        return (0);
    }
    if (my_strcmp(shell->command_shell[0], "unsetenv") == 0) {
        if (unsetenv_error(shell) == -1)
            return (-1);
        return (0);
    }
    if (my_strcmp(shell->command_shell[0], "setenv") == 0) {
        if (setenv_error(shell) == -1)
            return (-1);
        return (0);
    } else
        return (1);
}

void add_value(int value, shell_t *shell, char *add, int i)
{
    if (value != 0)
        for (int x = 0; shell->command_shell[2][x] != '\0'; x++) {
            add[i] = shell->command_shell[2][x];
            i++;
        }
}