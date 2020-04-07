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

void cd_dash_pwd(shell_t *shell, int loc_pwd, int loc_oldpwd, char *new)
{
    int x = 0;

    new[x] = 'P';
    x++;
    new[x] = 'W';
    x++;
    new[x] = 'D';
    x++;
    new[x] = '=';
    x++;
    for (int i = 7; shell->env_shell[loc_oldpwd][i] != '\0'; i++) {
        new[x] = shell->env_shell[loc_oldpwd][i];
        x++;
    }
    shell->env_shell[loc_pwd] = new;
    printf("| %s |\n| %s |\n", shell->env_shell[loc_pwd], shell->env_shell[loc_oldpwd]);
}

int cd_dash(shell_t *shell, int loc_pwd)
{
    int loc_oldpwd = location_of_oldpwd(shell);
    char *new = NULL;
    char *path = NULL;

    //if (replace_oldpwd(shell, loc_pwd, loc_oldpwd) == FAILURE)
    //    return (FAILURE);
    new = malloc(sizeof(char) * (my_strlen(shell->env_shell[loc_oldpwd] + 1)));
    if (new == NULL)
        return (FAILURE);
    path = malloc(sizeof(char) * (my_strlen(shell->env_shell[loc_pwd]- 4)));
    if (path == NULL)
        return (FAILURE);
    path[my_strlen(shell->env_shell[loc_pwd]) - 5] = '\0';
    new[my_strlen(shell->env_shell[loc_oldpwd])] = '\0';
    cd_dash_pwd(shell, loc_pwd, loc_oldpwd, new);
    change_pwd(shell, loc_pwd, path);
    return (0);
    // a revoir et ranger les fonctions
}