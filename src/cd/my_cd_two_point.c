/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_cd_two_point.c
*/

#include "fonctions.h"

void cd_with_point(shell_t *shell, int loc_pwd, char *new_pwd, char *stock)
{
    int x = 0;

    cd_two_point(shell, loc_pwd, stock);
    for (int i = 4; shell->env_shell[loc_pwd][i] != '\0'; i++) {
        new_pwd[x] = shell->env_shell[loc_pwd][i];
        x++;
    }
    chdir(new_pwd);
}

int cd_two_command(shell_t *shell, int loc_pwd, int loc_oldpwd, int a)
{
    int error = 0;

    if (shell->command_shell[1][0] == '-'
                                        && shell->command_shell[1][1] == '\0') {
        if (a == 0) {
            my_printf(": No such file or directory.\n");
            return (1);
        } else if (cd_dash(shell, loc_pwd) == FAILURE)
            return (FAILURE);
    }
    else {
        error = cd_with_path(shell, loc_pwd, loc_oldpwd);
        if (error == FAILURE)
            return (FAILURE);
        else if (error == 1)
            return (1);
    }
    return (0);
}