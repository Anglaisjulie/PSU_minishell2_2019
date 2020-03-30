/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** lib.h
*/

#ifndef LIB_H
#define LIB_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

//############################################################################//
//#################################//LIB//####################################//
//############################################################################//
////////////////////////////////////////////////////////////////////////////////
//MY_PRINTF/////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int my_printf(char *, ...);
void flags(va_list, char *, int);
int flags_char(va_list, int, char *);
int flags_b_p(va_list, int, char *);
int flags_int(va_list, int, char *);
////////////////////////////////////////////////////////////////////////////////
//LIBMY/////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void my_putchar(char);
int my_putstr(char *);
int my_put_nbr(int);
int my_strlen(char const *);
int my_putnbr_base (int, char const *);
int my_put_unsigned_nbr(unsigned int);
int	my_atoi(char *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strcpy(char *, char const *);
////////////////////////////////////////////////////////////////////////////////

#endif