/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** env_fils.c
*/

#include "fonctions.h"
#include <sys/types.h>
#include <sys/wait.h>

int all_fonctions(shell_t *shell)
{
    pid_t pid_fils;
    static int error = 0;

    if (shell->env_shell == NULL)
        return (-1);
    pid_fils = fork();
    if (pid_fils == 0) {
        for (int i = 0; shell->path_env[i] != NULL; i++) {
            error = my_path(shell, i, error);
        }
        if (error == -1) {
            my_printf("%s : Command not found.\n", shell->command_shell[0]);
            exit (0);
        }
    } else
        wait(NULL);
    return (0);
}

int my_path(shell_t *shell, int i, int error)
{
    if (shell->command_shell[0][0] == '.'
                                        && shell->command_shell[0][1] == '/') {
        error = execve(shell->command_shell[0],
                                    shell->command_shell, shell->env_shell);
    } else if (shell->command_shell[0][0] == '/') {
        error = execve(shell->command_shell[0],
                                    shell->command_shell, shell->env_shell);
    } else {
        error = execve(shell->path_env[i],
                                    shell->command_shell, shell->env_shell);
    }
    return (error);
}
