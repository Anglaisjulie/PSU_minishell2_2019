/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_cd_slash.c
*/

#include "fonctions.h"

int cd_slash(shell_t *shell, int loc_pwd)
{
    int loc_oldpwd = location_of_oldpwd(shell);
    char *new = NULL;

    new = malloc(sizeof(char) * (5 + 1));
    if (new == NULL)
        return (FAILURE);
    new[5] = '\0';
    new[0] = 'P';
    new[1] = 'W';
    new[2] = 'D';
    new[3] = '=';
    new[4] = '/';
    if (replace_oldpwd(shell, loc_pwd, loc_oldpwd) == FAILURE)
        return (FAILURE);
    shell->env_shell[loc_pwd] = new;
    chdir("/");
    return (0);
}