/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** fonctions.h
*/

#ifndef FONCTIONS_H
#define FONCTIONS_H

#include "lib.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#define FAILURE (84)
#define NO (-2)

#define SEMICOLON (1)
#define PIPE (2)
#define R_SIMPLE_LEFT (3)
#define R_SIMPLE_RIGHT (4)
#define R_DOUBLE_LEFT (5)
#define R_DOUBLE_RIGHT (6)


typedef struct shell_s {
    char **env_shell;
    char **command_shell;
    char **all_command;
    char **path_env;
    int nb_command;
    int number;
    char **av;
    char *exe;
    int value_return;
    int index_command;
    int len_total;
    int nb_command_one;
    int type_command;
    int check;
} shell_t;

//############################################################################//
//##########################//FONCTIONS PRINCIPALS//##########################//
//############################################################################//

////////////////////////////////////////////////////////////////////////////////
//SHELL/////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int my_sh(shell_t *);
////////////////////////////////////////////////////////////////////////////////
//ENV///////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int my_cpy_env(shell_t *, char **);
int malloc_env(shell_t *, char **);
int print_env(shell_t *);
////////////////////////////////////////////////////////////////////////////////
//COMMAND///////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int command_malloc(shell_t *, char *);
int my_command_shell(shell_t *, char *);
void count_command(shell_t *);
////////////////////////////////////////////////////////////////////////////////
//PATH//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int detection_path_env(shell_t *);
int my_path(shell_t *, int, int);
int next_spaces(char *);
void add_all_command(shell_t *, char *);
////////////////////////////////////////////////////////////////////////////////
//SETENV////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int malloc_stock_not_name(shell_t *);
int my_setenv(shell_t *);
int not_know_name(shell_t *, int, char **, int);
int malloc_env_notknow_name(shell_t *, char **);
int malloc_notknow_name(shell_t *, char **);
int add_name_value_env(shell_t *, int, int);
void add_value(int, shell_t *, char *, int);
int malloc_stock_not_name(shell_t *);
int malloc_stock_name(shell_t *, int);
int malloc_env_know_name(shell_t *, char **, int);
int malloc_know_name(shell_t *, char **, int);
int setenv_error(shell_t *);
int setenv_cmp(shell_t *, int, int);
////////////////////////////////////////////////////////////////////////////////
//UNSETENV/////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int my_unsetenv(shell_t *);
int unsetenv_error(shell_t *);
////////////////////////////////////////////////////////////////////////////////
//FONCTION PATH/////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int malloc_path(shell_t *);
int my_path_env(shell_t *);
int all_fonctions(shell_t *);
void add_command(shell_t *, int, int);
////////////////////////////////////////////////////////////////////////////////
//PROMPT////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int display_prompt(void);
////////////////////////////////////////////////////////////////////////////////
//CD////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int my_cd(shell_t *);
int location_of_oldpwd(shell_t *);
int location_of_home(shell_t *);
int location_of_pwd(shell_t *);
int cd_dash(shell_t *, int);
int replace_oldpwd(shell_t *, int, int);
int cd_with_path(shell_t *, int, int);
void change_pwd(shell_t *, int, char *);
int option_cd_path(shell_t *, int, char *, char *);
void cd_two_point(shell_t *, int, char *);
int cd_path_name(shell_t *, int, char *);
int cd_error(shell_t *, char *);
void cd_with_point(shell_t *, int, char *, char *);
int cd_two_command(shell_t *, int, int);
////////////////////////////////////////////////////////////////////////////////
//EXIT//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int my_exit(shell_t *);
////////////////////////////////////////////////////////////////////////////////
//SEPARATOR/////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int separator_shell(shell_t *);
////////////////////////////////////////////////////////////////////////////////


#endif