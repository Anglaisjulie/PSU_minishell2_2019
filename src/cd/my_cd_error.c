/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_cd_error.c
*/

#include "fonctions.h"
#include <sys/types.h>
#include <sys/stat.h>

int env_home(shell_t *shell)
{
    int a = 0;

    for (int i = 0; shell->env_shell[i] != NULL; i++) {
        if (my_strncmp(shell->env_shell[i], "HOME=", 5) == 0) {
            a++;
            printf("a1\n");
        }
        if (my_strncmp(shell->env_shell[i], "PWD=", 4) == 0) {
            a++;
            printf("a2\n");
        }
    }
    if (a == 2)
        return (0);
    return (FAILURE);
}

int env_oldpwd(shell_t *shell)
{
    int a = 0;
    int pwd = 0;
    int oldpwd = 0;

    for (int i = 0; shell->env_shell[i] != NULL; i++) {
        if (my_strncmp(shell->env_shell[i], "PWD=", 7) == 0)
            pwd = i;
    }
    for (int i = 0; shell->env_shell[i] != NULL; i++) {
        if (my_strncmp(shell->env_shell[i], "OLDPWD=", 7) == 0) {
            a++;
            oldpwd = i;
        }
    }
    if (my_strcmp(shell->env_shell[pwd], shell->env_shell[oldpwd]) == 0)
        a++;
    if (a == 2)
        return (0);
    return (FAILURE);
}

int other_error(shell_t *shell, char *path)
{
    struct stat stat_type;
    mode_t type;
    int error = 0;

    error = stat(path, &stat_type);
    type = stat_type.st_mode & S_IFMT;
    if (error != - 1 && type != S_IFDIR) {
        my_printf("%s: Not a directory.\n", shell->command_shell[1]);
        return (1);
    } else {
        my_printf("%s: No such file or directory.\n", shell->command_shell[1]);
        return (1);
    }
    return (0);
}

int cd_error(shell_t *shell, char *path)
{
    printf("a\n");
    if (env_home(shell) == FAILURE) {
        my_printf("%s: No home directory.\n", shell->command_shell[1]);
        return (1);
    }
    //if (env_oldpwd(shell) == FAILURE) {
    //    my_printf(": No such file or directory.\n");
    //    return (1);
    //}
    if (other_error(shell, path) == 1)
        return (1);
    return (0);
}