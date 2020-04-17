/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_prompt.c
*/

#include "fonctions.h"

int display_prompt(void)
{
    char *prompt = NULL;

    prompt = getcwd(NULL, 0);
    if (prompt == NULL)
        return (FAILURE);
    my_printf("[%s] $ ", prompt);
    free(prompt);
    return (0);
}