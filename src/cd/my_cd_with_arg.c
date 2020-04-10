/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_cd_arg2.c
*/

#include "fonctions.h"

int cd_dash_pwd(shell_t *shell, int loc_pwd, int loc_oldpwd, char *new)
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
    if (replace_oldpwd(shell, loc_pwd, loc_oldpwd) == FAILURE)
        return (FAILURE);
    shell->env_shell[loc_pwd] = new;
    return (0);
}

int cd_dash(shell_t *shell, int loc_pwd)
{
    int loc_oldpwd = location_of_oldpwd(shell);
    char *new = NULL;
    char *path = NULL;

    new = malloc(sizeof(char) * (my_strlen(shell->env_shell[loc_oldpwd] + 1)));
    if (new == NULL)
        return (FAILURE);
    path = malloc(sizeof(char) * (my_strlen(shell->env_shell[loc_oldpwd]) - 4));
    if (path == NULL)
        return (FAILURE);
    path[my_strlen(shell->env_shell[loc_oldpwd]) - 5] = '\0';
    new[my_strlen(shell->env_shell[loc_oldpwd])] = '\0';
    if (cd_dash_pwd(shell, loc_pwd, loc_oldpwd, new) == FAILURE)
        return (FAILURE);
    change_pwd(shell, loc_pwd, path);
    return (0);
}

void cd_pwd_with_path(shell_t *shell, int loc_pwd, char *pwd)
{
    int x = 0;

    pwd[x] = 'P';
    x++;
    pwd[x] = 'W';
    x++;
    pwd[x] = 'D';
    x++;
    pwd[x] = '=';
    x++;
    for (int i = 4; shell->env_shell[loc_pwd][i] != '\0'; i++) {
        pwd[x] = shell->env_shell[loc_pwd][i];
        x++;
    }
    pwd[x] = '/';
    for (int i = 0; shell->command_shell[1][i] != '\0'; i++) {
        x++;
        pwd[x] = shell->command_shell[1][i];
    }
    shell->env_shell[loc_pwd] = pwd;
}

int cd_path_name(shell_t *shell, int loc_pwd, char *path)
{
    int x = 0;

    for (int i = 4; shell->env_shell[loc_pwd][i] != '\0'; i++) {
        path[x] = shell->env_shell[loc_pwd][i];
        x++;
    }
    path[x] = '/';
    for (int i = 0; shell->command_shell[1][i] != '\0'; i++) {
        x++;
        path[x] = shell->command_shell[1][i];
    }
    if (chdir(path) == - 1) {
        cd_error(shell, path);
        return (NO);
    }
    return (0);
}

int option_cd_path(shell_t *shell, int loc_pwd, char *pwd, char *path)
{
    char *new_pwd = NULL;
    char *stock = NULL;

    new_pwd = malloc(sizeof(char) * (my_strlen(shell->env_shell[loc_pwd])));
    if (new_pwd == NULL)
        return (FAILURE);
    stock = malloc(sizeof(char) * (my_strlen(shell->env_shell[loc_pwd])));
    if (stock == NULL)
        return (FAILURE);
    if (my_strlen(shell->command_shell[1]) == 1
        && shell->command_shell[1][0] == '.') {}
    if (my_strlen(shell->command_shell[1]) == 2
        && shell->command_shell[1][0] == '.'
        && shell->command_shell[1][1] == '.') {
        cd_with_point(shell, loc_pwd, new_pwd, stock);
    } else
        cd_pwd_with_path(shell, loc_pwd, pwd);
    return (0);
}