##
## EPITECH PROJECT, 2019
## Makefile.c
## File description:
## makefile
##

RM =	rm -rf

CC =	gcc -o

SRC_DIR =	src/

FILE_LIST = 	cpy_env.c 								 \
				main.c 									 \
				my_unsetenv.c							 \
				env_fils.c                      	     \
				my_path.c                       	     \
				my_prompt.c                       	     \
				my_setenv_error.c               	     \
				my_setenv_name.c                	     \
				my_setenv_not_name.c            	     \
				my_sh.c                         	     \
				my_cd.c                         	     \
				my_basic_cd.c                            \
				my_str_to_word_array.c          	     \

SRC	= 	$(addprefix $(SRC_DIR), $(FILE_LIST))

OBJ	=	$(SRC:.c=.o)

NAME =	mysh

CFLAGS =	-W -Wall -L./lib/ -lmy -I./include/
CFLAGS +=	-fdiagnostics-color
CFLAGS +=	-g3


all:	$(NAME) clean

$(NAME):	$(OBJ)
			make -C ./lib/
			@echo -e "\033[1;33m[COMPILING TETRIS...]\033[0;30m"
			$(CC) $@ $^ $(CFLAGS)
			$(RM) $(addprefix $(SRC_DIR), *.o)
			@echo -e "\033[1;32m[SUCCESSFULLY TETRIS COMPLETED]\033[0;37m"

clean:
	$(RM) $(OBJ)

fclean:		clean
			$(RM) lib/libmy.a
			@echo -e "\033[1;34m[CLEAN LIB OK]\033[0;30m"
			$(RM) $(NAME)
			$(RM) Makefile~
			@echo -e "\033[1;34m[CLEAN TETRIS OK]\033[0;30m"

re: 	fclean all