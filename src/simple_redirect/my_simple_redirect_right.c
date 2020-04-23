/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_simple_redirect_right.c
*/

#include "fonctions.h"
#include <sys/stat.h>

int def_sizemap(char *command)
{
    struct stat size;
    int len = 0;

    stat(command, &size);
    len = size.st_size;
    return (len);
}

int read_files(shell_t *shell, int location)
{
    int len = def_sizemap(shell->command_shell[location]);
    int fd = 0;
    int size = 0;
    char *buffer = 0;

    fd = fopen(shell->command_shell[location], "w+");
    if (fd <= 0)
        return (84);
    size = read(fd, buffer, len);
    if (size == 0)
        return (84);
    buffer[size] = '\0';
    close(fd);
}