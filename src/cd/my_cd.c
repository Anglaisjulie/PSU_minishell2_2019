/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_cd.c
*/

#include "fonctions.h"

int location_of_pwd(shell_t *shell)
{
    int location = 0;

    for (int i = 0; shell->env_shell[i] != NULL; i++) {
        if (my_strncmp(shell->env_shell[i], "PWD=", 4) == 0) {
            location = i;
            break;
        }
    }
    return (location);
}

int location_of_home(shell_t *shell)
{
    int location = 0;

    for (int i = 0; shell->env_shell[i] != NULL; i++) {
        if (my_strncmp(shell->env_shell[i], "HOME=", 5) == 0) {
            location = i;
            break;
        }
    }
    return (location);
}

int location_of_oldpwd(shell_t *shell)
{
    int location = 0;

    for (int i = 0; shell->env_shell[i] != NULL; i++) {
        if (my_strncmp(shell->env_shell[i], "OLDPWD=", 7) == 0) {
            location = i;
            break;
        }
    }
    return (location);
}

void change_pwd(shell_t *shell, int loc_pwd, char *path)
{
    int x = 0;

    for (int i = 4; shell->env_shell[loc_pwd][i] != '\0'; i++) {
        path[x] = shell->env_shell[loc_pwd][i];
        x++;
    }
    chdir(path);
}

int replace_oldpwd(shell_t *shell, int loc_pwd, int loc_oldpwd)
{
    char *oldpwd = NULL;
    int a = 0;

    oldpwd = malloc(sizeof(char) * (my_strlen(shell->env_shell[loc_pwd] + 4)));
    if (oldpwd == NULL)
        return (FAILURE);
    oldpwd[a] = 'O';
    a++;
    oldpwd[a] = 'L';
    a++;
    oldpwd[a] = 'D';
    a++;
    for (int i = 0; shell->env_shell[loc_pwd][i] != '\0'; i++) {
        oldpwd[a] = shell->env_shell[loc_pwd][i];
        a++;
    }
    shell->env_shell[loc_oldpwd] = oldpwd;
    return (0);
}
