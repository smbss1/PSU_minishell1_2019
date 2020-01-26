#
# EPITECH PROJECT, 2019
# Makefile
# File description:
# make an executable
#

SRC = 	main.c my_event.c \
		my_command.c my_execvp.c debug.c \
		getenv.c execute.c update.c \
		set_env.c unset_env.c my_strcat_dup.c
OBJ = $(SRC:.c=.o)
NAME = mysh

CFLAGS += -I ./include/
CFLAGS += -L ./lib/
CFLAGS += -lmy
CFLAGS += -lgc
CFLAGS += -W -Wall
CFLAGS += -g3

bold = [1m
green = [32m
yellow = [33m
blue = [34m
white = [37m
reset = (B[m

all: $(NAME)

lib_make:
	@make -s -C lib/my
	@make -s -C lib/tiny_garbage

$(NAME): lib_make $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)

%.o : %.c
	@gcc $(CFLAGS) -c $< -o $@
	@echo "$(bold)$(green)Compiled $(white)'$<'$(reset)"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f vgcore*
	@make fclean -s -C lib/my
	@make fclean -s -C lib/tiny_garbage

re: fclean all

install:
	@echo "Install"

run:
	./$(NAME)
