/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** cpy_env.c
*/

#include "fonctions.h"

int my_cpy_env(shell_t *shell, char **env)
{
    if (malloc_env(shell, env) == 84)
        return (84);
    for (int i = 0; env[i] != NULL; i++) {
        for (int j = 0; env[i][j] != '\0'; j++)
            shell->env_shell[i][j] = env[i][j];
    }
    return (0);
}

int malloc_env(shell_t *shell, char **env)
{
    int size_line = 0;
    int char_line = 0;

    for (int i = 0; env[i] != NULL; i++)
        size_line++;
    shell->env_shell = malloc(sizeof(char *) * (size_line + 1));
    shell->env_shell[size_line] = NULL;
    if (shell->env_shell == NULL)
        return (84);
    for (int i = 0; env[i] != NULL; i++) {
        char_line = my_strlen(env[i]);
        shell->env_shell[i] = malloc(sizeof(char) * (char_line + 1));
        shell->env_shell[i][char_line] = '\0';
        if (shell->env_shell[i] == NULL)
            return (84);
    }
    return (0);
}

int print_env(shell_t *shell)
{
    if (shell->env_shell == NULL)
        return (-1);
    for (int i = 0; shell->env_shell[i] != NULL; i++)
        my_printf("%s\n", shell->env_shell[i]);
    return (0);
}