/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_path.c
*/

#include "fonctions.h"

int detection_path_env(shell_t *shell)
{
    int location = -1;
    int n = 0;

    for (int i = 0; shell->env_shell[i] != NULL; i++)
        if (my_strncmp(shell->env_shell[i], "PATH=", 5) == 0)
            location = i;
    if (location == -1)
        return (84);
    for (int i = 0; shell->env_shell[location][i] != '\0'; i++)
        if (shell->env_shell[location][i] == ':')
            n++;
    n += 1;
    shell->path_env = malloc(sizeof(char *) * (n + 1));
    if (shell->path_env == NULL)
        return (84);
    shell->path_env[n] = NULL;
    return (location);
}

int malloc_path(shell_t *shell, char *command)
{
    int location = detection_path_env(shell);
    int x = 0;
    int a = 0;
    int size_command = my_strlen(command);

    if (location == -1)
        return (-1);
    for (int i = 0; shell->env_shell[location][i] != '\0'; i++) {
        if (shell->env_shell[location][i] == ':') {
            shell->path_env[x] = malloc(sizeof(char) * (a + size_command + 2));
            shell->path_env[x][a + size_command + 1] = '\0';
            a = 0;
            x++;
        } else
            a++;
    }
    shell->path_env[x] = malloc(sizeof(char) * (a + size_command + 2));
    shell->path_env[x][a + size_command + 1] = '\0';
    return (location);
}

int my_path_env(shell_t *shell, char *command)
{
    int location = 0;
    int x = 0;
    int a = 0;

    if (shell->env_shell == NULL)
        return (-1);
    location = malloc_path(shell, command);
    if (location == -1)
        return (-1);
    for (int i = 5; shell->env_shell[location][i] != '\0'; i++) {
        if (shell->env_shell[location][i] == ':') {
            a = 0;
            x++;
        } else {
            shell->path_env[x][a] = shell->env_shell[location][i];
            a++;
        }
    }
    return (0);
}

void add_command(shell_t *shell, int x, int a)
{
    shell->path_env[x][a] = '/';
    for (int y = 0; shell->command_shell[0][y] != '\0'; y++)
        shell->path_env[x][a + (y + 1)] = shell->command_shell[0][y];
}

void count_command(shell_t *shell)
{
    for (int i = 0; i != shell->nb_command; i++) {
        if (shell->all_command[i][0] == ';') {
            shell->number++;
        }
    }
    shell->number++;
}