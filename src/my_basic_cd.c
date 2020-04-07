/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_cd.c
*/

#include "fonctions.h"

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

void change_pwd(shell_t *shell, int loc_pwd, char *path)
{
    int loc_home = location_of_home(shell);
    int x = 0;

    for (int i = 5; shell->env_shell[loc_home][i] != '\0'; i++) {
        path[x] = shell->env_shell[loc_home][i];
        x++;
    }
    chdir(path);
}

int simple_cd(shell_t *shell, int loc_pwd, int loc_oldpwd)
{
    char *home = NULL;
    char *path = NULL;
    int loc_home = location_of_home(shell);

    if (replace_oldpwd(shell, loc_pwd, loc_oldpwd) == FAILURE)
        return (FAILURE);
    home = malloc(sizeof(char) * (my_strlen(shell->env_shell[loc_home] + 1)));
    if (home == NULL)
        return (FAILURE);
    home[my_strlen(shell->env_shell[loc_home])] = '\0';
    path = malloc(sizeof(char) * (my_strlen(shell->env_shell[loc_pwd]- 4)));
    if (path == NULL)
        return (FAILURE);
    path[my_strlen(shell->env_shell[loc_pwd]) - 5] = '\0';
    new_pwd(shell, loc_pwd, home);
    change_pwd(shell, loc_pwd, path);
    return (0);
}

int my_cd(shell_t *shell)
{
    int loc_pwd = location_of_pwd(shell);
    int loc_oldpwd = location_of_oldpwd(shell);
    int nb_command = 0;

    for (; shell->command_shell[nb_command] != NULL; nb_command++);
    if (nb_command == 1)
        if (simple_cd(shell, loc_pwd, loc_oldpwd) == FAILURE)
            return (FAILURE);
    if (nb_command == 2) {
        if (shell->command_shell[1][0] == '-'
                                        && shell->command_shell[1][1] == '\0') {
            if (cd_dash(shell, loc_pwd) == FAILURE)
                return (FAILURE);
        }
        //if (shell->command_shell[1] == "..");
    }

    return (0);
}