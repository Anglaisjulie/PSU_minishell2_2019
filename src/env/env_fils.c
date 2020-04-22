/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** env_fils.c
*/

#include "fonctions.h"
#include <sys/types.h>
#include <sys/wait.h>

void pid_fils_action(shell_t *shell, int error)
{
    for (int i = 0; shell->path_env[i] != NULL; i++)
        error = my_path(shell, i, error);
    if (error == -1) {
        my_printf("%s : Command not found.\n", shell->command_shell[0]);
        exit (0);
    }
}

int all_fonctions(shell_t *shell)
{
    pid_t pid_fils;
    static int error = 0;

    if (shell->env_shell == NULL)
        return (-1);
    pid_fils = fork();
    if (pid_fils == 0) {
        pid_fils_action(shell, error);
    } else
        wait(NULL);
    return (0);
}

int create_av(shell_t *shell, int i)
{
    int len = shell->nb_command_one;

    shell->av = malloc(sizeof(char *) * (len + 1));
    if (shell->av == NULL)
        return (FAILURE);
    shell->av[len] = NULL;
    shell->av[0] = shell->path_env[i];
    for (int i = 1; i != len; i++)
        shell->av[i] = shell->command_shell[i];
    return (0);
}

int my_path(shell_t *shell, int i, int error)
{
    if (create_av(shell, i) == FAILURE)
        return (FAILURE);
    if (shell->command_shell[0][0] == '.'
                                        && shell->command_shell[0][1] == '/') {
        error = execve(shell->command_shell[0],
                                    shell->command_shell, shell->env_shell);
    } else if (shell->command_shell[0][0] == '/') {
        error = execve(shell->command_shell[0],
                                    shell->command_shell, shell->env_shell);
    } else
        error = execve(shell->av[0], shell->av, shell->env_shell);
    return (error);
}
