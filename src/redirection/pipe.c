/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** pipe.c
*/

#include "fonctions.h"

int command_first(shell_t *shell, int *pipefd)
{
    int error = 0;

    shell->command_shell = shell->command_one;
    close(pipefd[0]);
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[1]);
    error = option_shell(shell);
    if (error == NO) {
        my_path_env(shell);
        error = all_fonctions(shell);
    }
    return (error);
}

int command_second(shell_t *shell, int *pipefd)
{
    int error = 0;

    shell->command_shell = shell->command_two;
    close(pipefd[1]);
    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[0]);
    error = option_shell(shell);
    if (error == NO) {
        my_path_env(shell);
        error = all_fonctions(shell);
    }
    return (error);
}

int exe_pipe(shell_t *shell, int start, int end)
{
    pid_t pid = 0;
    int pipefd[2];
    int fd[2];
    int error = 0;

    pipe(pipefd);
    fd[0] = dup(STDIN_FILENO);
    fd[1] = dup(STDOUT_FILENO);
    pid = fork();
    if (pid == -1)
        return (FAILURE);
    if (pid == 0)
        error = command_first(shell, pipefd);
    else
        error = command_second(shell, pipefd);
    dup2(fd[0], STDIN_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(pipefd[0]);
    close(pipefd[1]);
    return (error);
}