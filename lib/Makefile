##
## EPITECH PROJECT, 2019
## PSU_my_sokoban_2019
## File description:
## Makefile
##

RM =	rm -rf

CC =	gcc -c

SRC =	*.c		\

OBJ	=	$(SRC:.c=.o)

NAME =	libmy.a

CFLAGS =	-I../include/

all:   $(NAME) clean

$(NAME):	$(OBJ)
			@echo -e "\033[1;33m[COMPILING LIB...]\033[0;30m"
			$(CC) $(SRC) $(CFLAGS)
			ar rc $(NAME) $(OBJ)
			@echo -e "\033[1;32m[SUCCESSFULLY LIB COMPLETED]\033[0;30m"

clean:
	$(RM) $(OBJ)
