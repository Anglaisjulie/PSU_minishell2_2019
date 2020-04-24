/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_cd.c
*/

#include "fonctions.h"

void new_pwd(shell_t *shell, int loc_pwd, char *home)
{
    int loc_home = location_of_home(shell);
    int x = 0;

    home[x] = 'P';
    x++;
    home[x] = 'W';
    x++;
    home[x] = 'D';
    x++;
    home[x] = '=';
    x++;
    for (int i = 5; shell->env_shell[loc_home][i] != '\0'; i++) {
        home[x] = shell->env_shell[loc_home][i];
        x++;
    }
    shell->env_shell[loc_pwd] = home;
}

int simple_cd(shell_t *shell, int loc_pwd, int loc_oldpwd)
{
    char *home = NULL;
    char *path = NULL;
    int loc_home = location_of_home(shell);

    if (replace_oldpwd(shell, loc_pwd, loc_oldpwd) == FAILURE)
        return (FAILURE);
    home = malloc(sizeof(char) * (my_strlen(shell->env_shell[loc_home]) + 1));
    if (home == NULL)
        return (FAILURE);
    home[my_strlen(shell->env_shell[loc_home])] = '\0';
    path = malloc(sizeof(char) * (my_strlen(shell->env_shell[loc_pwd]) - 4));
    if (path == NULL)
        return (FAILURE);
    path[my_strlen(shell->env_shell[loc_pwd]) - 5] = '\0';
    new_pwd(shell, loc_pwd, home);
    change_pwd(shell, loc_pwd, path);
    return (0);
}

int cd_with_path(shell_t *shell, int loc_pwd, int loc_oldpwd)
{
    char *path = NULL;
    char *pwd = NULL;
    int size = my_strlen(shell->command_shell[1])
                                    + 1 + my_strlen(shell->env_shell[loc_pwd]);

    path = malloc(sizeof(char) * (size - 3));
    if (path == NULL)
        return (FAILURE);
    if (cd_path_name(shell, loc_pwd, path) == 1)
        return (1);
    if (replace_oldpwd(shell, loc_pwd, loc_oldpwd) == FAILURE)
        return (FAILURE);
    pwd = malloc(sizeof(char) * (size + 1));
    if (pwd == NULL)
        return (FAILURE);
    if (option_cd_path(shell, loc_pwd, pwd, path) == FAILURE)
        return (FAILURE);
    return (0);
}

void cd_two_point(shell_t *shell, int loc_pwd, char *stock)
{
    int loc_oldpwd = location_of_oldpwd(shell);
    int slash = 0;
    int count = 0;
    int x = 0;

    for (int i = 7; shell->env_shell[loc_oldpwd][i] != '\0'; i++) {
        if (shell->env_shell[loc_oldpwd][i] == '/')
            slash++;
    }
    for (int i = 3; shell->env_shell[loc_oldpwd][i] != '\0'; i++) {
        if (shell->env_shell[loc_oldpwd][i] == '/')
            count++;
        if (count < slash) {
            stock[x] = shell->env_shell[loc_oldpwd][i];
            x++;
        }
    }
    shell->env_shell[loc_pwd] = stock;
}

int my_cd(shell_t *shell)
{
    int loc_pwd = location_of_pwd(shell);
    int loc_oldpwd = location_of_oldpwd(shell);
    int error = 0;

    if (env_home(shell) == FAILURE) {
        my_printf("%s: No home directory.\n", shell->command_shell[0]);
        return (1);
    }
    if (shell->nb_command_one == 1)
        if (simple_cd(shell, loc_pwd, loc_oldpwd) == FAILURE)
            return (FAILURE);
    if (shell->nb_command_one == 2) {
        error = cd_two_command(shell, loc_pwd, loc_oldpwd);
        if (error == FAILURE)
            return (FAILURE);
        else if (error == 1)
            return (1);
    }
    if (shell->nb_command_one > 2) {
        my_printf("%s: Too many arguments.\n", shell->command_shell[0]);
        return (1);
    }
    return (0);
}