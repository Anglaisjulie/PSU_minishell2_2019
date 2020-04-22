/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_cd_error.c
*/

#include "fonctions.h"
#include <sys/types.h>
#include <sys/stat.h>

int cd_error(shell_t *shell, char *path)
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