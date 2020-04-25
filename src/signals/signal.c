/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** signal.c
*/

#include "fonctions.h"

void handler(int num)
{
    switch (num)
    {
    case SIGINT:
        my_putstr("\n");
        display_prompt();
        break;
    case SIGSEGV:
        my_printf("Error.\n");
        exit(84);
    case SIGPIPE:
        my_printf("Error.\n");
        exit(84);
    }
}

void check_signals(void)
{
    signal(SIGINT, handler);
    signal(SIGPIPE, handler);
}

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
    if (a == 1)
        my_putchar('\n');
    return (error);
}