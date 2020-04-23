/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_setenv_name.c
*/

#include "fonctions.h"

int my_setenv(shell_t *shell)
{
    int len = my_strlen(shell->command_shell[1]);
    int i = 0;

    for (int a = 0; shell->command_shell[1][a] != '\0'; a++)
        if (shell->command_shell[1][a] == '=') {
            my_printf
            ("setenv: Variable name must contain alphanumeric characters.\n");
            return (1);
        }
    for (; shell->env_shell[i] != NULL; i++) {
        if (my_strncmp(shell->env_shell[i], shell->command_shell[1], len)
                                                                == 0) {
            if (malloc_stock_name(shell, i) == -1)
                return (-1);
            return (0);
        }
    }
    if (malloc_stock_not_name(shell) == -1)
        return (-1);
    return (0);
}

int malloc_stock_name(shell_t *shell, int modified)
{
    char **stock = NULL;
    int i = 0;
    int len = 0;

    for (; shell->env_shell[i] != NULL; i++);
    stock = malloc(sizeof(char *) * (i + 1));
    stock[i] = NULL;
    if (stock == NULL)
        return (-1);
    for (int j = 0; shell->env_shell[j] != NULL; j++) {
        len = my_strlen(shell->env_shell[j]);
        stock[j] = malloc(sizeof(char) * (len + 1));
        stock[j][len] = '\0';
        if (stock[j] == NULL)
            return (84);
    }
    if (malloc_env_know_name(shell, stock, modified) == 84)
        return (-1);
    return (0);
}

int malloc_env_know_name(shell_t *shell, char **stock, int modified)
{
    int i = 0;
    int max = 0;
    int z = 0;

    for (int k = 0; shell->env_shell[k] != NULL; k++) {
        stock[k] = my_strcpy(stock[k], shell->env_shell[k]);
    }
    for (; stock[i] != NULL; i++);
    shell->env_shell = malloc(sizeof(char *) * (i + 1));
    shell->env_shell[i] = NULL;
    if (shell->env_shell == NULL)
        return (84);
    max = malloc_know_name(shell, stock, modified);
    if (max == -1)
        return (84);
    add_name_value_env(shell, max, z);
    return (0);
}

int malloc_know_name(shell_t *shell, char **stock, int modified)
{
    int j = 0;
    int line_size = 0;
    int name = my_strlen(shell->command_shell[1]);
    int value = my_strlen(shell->command_shell[2]);

    if (name == 0 && value == 0)
        return (84);
    for (; stock[j] != NULL; j++) {
        line_size = my_strlen(stock[j]);
        shell->env_shell[modified] = malloc(sizeof(char) * (name + value + 2));
        shell->env_shell[modified][name + value + 1] = '\0';
        shell->env_shell[j] = malloc(sizeof(char) * (line_size + 1));
        shell->env_shell[j][line_size] = '\0';
        shell->env_shell[j] = my_strcpy(shell->env_shell[j], stock[j]);
        if (shell->env_shell[j] == NULL)
            return (-1);
    }
    return (modified);
}