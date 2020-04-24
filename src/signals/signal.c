/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** signal.c
*/

#include "fonctions.h"

int check_segfault(int status)
{
    int error = 0;
    int a = 0;

    if (WTERMSIG(status) == SIGSEGV) {
        my_printf("Segmentation fault");
        error = 139;
        a = 1;
    } else if (WTERMSIG(status) == SIGFPE) {
        my_printf("Floating exception");
        error = 136;
        a = 1;
    }
    if (WCOREDUMP(status))
        my_printf(" (core dumped)");
    (a == 1 ? my_putchar('\n') : 0);
    return (error);
}