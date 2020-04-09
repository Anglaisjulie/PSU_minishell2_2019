/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_setenv.c
*/

#include "fonctions.h"

int malloc_stock_not_name(shell_t *shell)
{
    char **stock = NULL;
    int i = 0;
    int len = 0;

    for (; shell->env_shell[i] != NULL; i++);
    stock = malloc(sizeof(char *) * (i + 1));
    stock[i] = NULL;
    if (stock == NULL)
        return (84);
    for (int j = 0; shell->env_shell[j] != NULL; j++) {
        len = my_strlen(shell->env_shell[j]);
        stock[j] = malloc(sizeof(char) * (len + 1));
        stock[j][len] = '\0';
        if (stock[j] == NULL)
            return (84);
    }
    if (malloc_env_notknow_name(shell, stock) == 84)
        return (84);
    return (0);
}

int malloc_env_notknow_name(shell_t *shell, char **stock)
{
    int i = 0;
    int max = 0;
    int z = 0;

    for (int k = 0; shell->env_shell[k] != NULL; k++) {
        stock[k] = my_strcpy(stock[k], shell->env_shell[k]);
        free(shell->env_shell[k]);
    }
    free(shell->env_shell);
    for (; stock[i] != NULL; i++);
    shell->env_shell = malloc(sizeof(char *) * (i + 2));
    shell->env_shell[i + 1] = NULL;
    if (shell->env_shell == NULL)
        return (84);
    max = malloc_notknow_name(shell, stock);
    if (max == -1)
        return (84);
    add_name_value_env(shell, max, z);
    return (0);
}

int malloc_notknow_name(shell_t *shell, char **stock)
{
    int j = 0;
    int line_size = 0;
    int name = my_strlen(shell->command_shell[1]);
    int value = my_strlen(shell->command_shell[2]);

    if (name == 0 && value == 0)
        return (84);
    j = not_know_name(shell, j, stock, line_size);
    if (j == -1)
        return (-1);
    shell->env_shell[j] = malloc(sizeof(char) * (name + value + 2));
    shell->env_shell[j][name + value + 1] = '\0';
    if (shell->env_shell[j] == NULL)
        return (-1);
    return (j);
}

int not_know_name(shell_t *shell, int j, char **stock, int line_size)
{
    for (; stock[j] != NULL; j++) {
        line_size = my_strlen(stock[j]);
        shell->env_shell[j] = malloc(sizeof(char) * (line_size + 1));
        shell->env_shell[j][line_size] = '\0';
        shell->env_shell[j] = my_strcpy(shell->env_shell[j], stock[j]);
        free(stock[j]);
        if (shell->env_shell[j] == NULL)
            return (-1);
    }
    free(stock);
    return (j);
}

int add_name_value_env(shell_t *shell, int j, int i)
{
    char *add = NULL;
    int name = my_strlen(shell->command_shell[1]);
    int value = my_strlen(shell->command_shell[2]);

    if (name == 0 && value == 0)
        return (84);
    add = malloc(sizeof(char) * (name + value + 2));
    add[name + value + 1] = '\0';
    if (add == NULL)
        return (84);
    for (; shell->command_shell[1][i] != '\0'; i++)
        add[i] = shell->command_shell[1][i];
    add[i] = '=';
    i++;
    add_value(value, shell, add, i);
    shell->env_shell[j] = my_strcpy(shell->env_shell[j], add);
    free(add);
    return (0);
}