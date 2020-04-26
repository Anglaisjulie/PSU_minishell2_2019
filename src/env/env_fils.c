/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** env_fils.c
*/

#include "fonctions.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int pid_fils_action(shell_t *shell, int error)
{
    for (int i = 0; shell->path_env[i] != NULL; i++)
        error = my_path(shell, i, error);
    if (error == -1 || error == 2) {
        if (errno == EACCES) {
            my_printf("%s: Permission denied.", shell->command_shell[0]);
            return (1);
        }
        if (errno == ENOENT) {
            my_printf("%s: Command not found.", shell->command_shell[0]);
            return (1);
        }
        if (errno == ENOTDIR) {
            my_printf("%s: Not a directory.", shell->command_shell[0]);
            return (1);
        }
        if (errno == ENOTDIR) {
            my_printf("%s: No such file or directory.", shell->command_shell[0]);
            return (1);
        }
    }
    return (0);
}

int all_fonctions(shell_t *shell)
{
    pid_t pid_fils;
    static int error = 0;
    int status = 0;

    if (shell->env_shell == NULL)
        return (-1);
    pid_fils = fork();
    if (pid_fils == 0)
        status = pid_fils_action(shell, error);
    else
        wait(&status);
    return (check_segfault(status));
}

int create_av(shell_t *shell, int i)
{
    int len = shell->nb_command_one;
    int a = my_strlen(shell->path_env[i]);

    add_command(shell, i, a);
    shell->av = malloc(sizeof(char *) * (len + 1));
    if (shell->av == NULL)
        return (FAILURE);
    shell->av[len] = NULL;
    shell->av[0] = shell->path_env[i];
    for (int i = 1; i != len; i++)
        shell->av[i] = shell->command_shell[i];
    return (0);
}

int option_exe(shell_t *shell, int error)
{
    if (shell->command_shell[0][0] == '.'
                                        && shell->command_shell[0][1] == '/') {
        shell->exe = shell->command_shell[0];
        shell->av[0] = shell->command_shell[0];
        error = execve(shell->exe, shell->av, shell->env_shell);
    } else if (shell->command_shell[0][0] == '/') {
        shell->exe = shell->command_shell[0];
        shell->av[0] = shell->command_shell[0];
        error = execve(shell->exe, shell->av, shell->env_shell);
    } else {
        shell->exe = shell->av[0];
        shell->av[0] = shell->command_shell[0];
        error = execve(shell->exe, shell->av, shell->env_shell);
    }
    return (error);
}

int my_path(shell_t *shell, int i, int error)
{
    shell->exe = NULL;
    if (create_av(shell, i) == FAILURE)
        return (FAILURE);
    if (shell->command_shell[0][0] == '.'
        && shell->command_shell[0][1] == '.' && shell->check == 0) {
        shell->check++;
        return (1);
    } else if (shell->check > 0) {
        errno = ENOENT;
        return (2);
    }
    error = option_exe(shell, error);
    return (error);
}
