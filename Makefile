##
## EPITECH PROJECT, 2019
## Makefile.c
## File description:
## makefile
##

RM =	rm -rf

CC =	gcc -o

SRC_DIR =	src/

FILE_LIST =		main.c 									 \
				my_sh.c                         	     \
				bonus/my_prompt.c                 	     \
				env/cpy_env.c 							 \
				env/env_fils.c                           \
				exit/exit.c   			                 \
				path_command/my_path.c           	     \
				path_command/add_all_command.c     	     \
				path_command/my_str_to_word_array.c      \
				path_command/separate_command.c     	 \
				setenv/my_setenv_name.c            	     \
				setenv/my_setenv_not_name.c        	     \
				setenv/my_setenv_error.c                 \
				unsetenv/my_unsetenv.c		     		 \
				unsetenv/my_unsetenv_error.c             \
				cd/my_cd.c                         	     \
				cd/my_basic_cd.c                         \
				cd/my_cd_two_point.c                     \
				cd/my_cd_with_arg.c                      \
				cd/my_cd_slash.c                         \
				cd/my_cd_error.c                         \
				semicolons/semicolon.c                   \
				signals/signal.c        				 \

SRC	= 	$(addprefix $(SRC_DIR), $(FILE_LIST))

OBJ	=	$(SRC:.c=.o)

NAME =	mysh

CFLAGS =	-W -Wall -L./lib/ -lmy -I./include/
CFLAGS +=	-fdiagnostics-color
CFLAGS +=	-g3


all:	$(NAME) clean

$(NAME):	$(OBJ)
			make -C ./lib/
			@echo -e "\033[1;33m[COMPILING TETRIS...]\033[0;32m"
			$(CC) $@ $^ $(CFLAGS)
			$(RM) $(addprefix $(SRC_DIR), *.o)
			$(RM) $(addprefix $(SRC_DIR), */*.o)
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