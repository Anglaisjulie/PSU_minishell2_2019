/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_unsetenv.c
*/

#include "fonctions.h"

int malloc_unsetenv(shell_t *shell, char **stock, int deleted)
{
    int line_size = 0;
    int i = 0;

    for (int j = 0; stock[j] != NULL; j++) {
        line_size = my_strlen(stock[j]);
        shell->env_shell[j] = malloc(sizeof(char) * (line_size + 1));
        if (shell->env_shell[j] == NULL)
            return (-1);
        shell->env_shell[j][line_size] = '\0';
    }
    for (; i < deleted; i++)
        shell->env_shell[i] = my_strcpy(shell->env_shell[i], stock[i]);
    for (int j = i + 1; stock[j] != NULL; j++)
        shell->env_shell[j - 1] = my_strcpy(shell->env_shell[j - 1], stock[j]);
    return (0);
}

int malloc_env_unsetenv(shell_t *shell, char **stock, int deleted)
{
    int i = 0;
    int max = 0;

    for (int k = 0; shell->env_shell[k] != NULL; k++)
        stock[k] = my_strcpy(stock[k], shell->env_shell[k]);
    for (; stock[i] != NULL; i++);
    shell->env_shell = malloc(sizeof(char *) * (i + 1));
    shell->env_shell[i] = NULL;
    if (shell->env_shell == NULL)
        return (84);
    max = malloc_unsetenv(shell, stock, deleted);
    if (max == -1)
        return (84);
    return (0);
}

int malloc_stock_unsetenv(shell_t *shell, int deleted)
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
    if (malloc_env_unsetenv(shell, stock, deleted) == 84)
        return (84);
    return (0);
}

int my_unsetenv_option(shell_t *shell, int len, int i)
{
    if (my_strncmp(shell->command_shell[1], shell->env_shell[i], len) == 0)
        if (malloc_stock_unsetenv(shell, i) == 84)
            return (-1);
    return (0);
}

int my_unsetenv(shell_t *shell)
{
    int i = 0;
    int len = my_strlen(shell->command_shell[1]);

    for (int a = 0; shell->command_shell[1][a] != '\0'; a++)
        if (shell->command_shell[1][a] == '=')
            return (-1);
    for (; shell->env_shell[i] != NULL; i++)
        if (my_unsetenv_option(shell, len, i) == -1)
            return (-1);
    return (0);
}