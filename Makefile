#
# EPITECH PROJECT, 2019
# Makefile
# File description:
# make an executable
#

SRC = 	main.c my_event.c \
		my_command.c my_execvp.c debug.c \
		getenv.c execute.c update.c \
		set_env.c unset_env.c my_strcat_dup.c \
		my_cd.c my_str_clean.c
OBJ = $(SRC:.c=.o)
NAME = mysh
_SRC = execute.c my_execvp.c my_strcat_dup.c getenv.c set_env.c debug.c \
		unset_env.c
TEST_SRC =	bonus/tests/test_execute.c \
			bonus/tests/test_setenv.c \
			bonus/tests/test_getenv.c \
			bonus/tests/test_unset_env.c
TEST_NAME = unit_tests

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
	@rm -f *.gcno
	@rm -f *.gcda

fclean: clean
	@rm -f $(NAME)
	@rm -f $(TEST_NAME)
	@rm -f vgcore*
	@make fclean -s -C lib/my
	@make fclean -s -C lib/tiny_garbage

re: fclean all

install:
	@echo "Install"

run:
	./$(NAME)

run_tests: lib_make
		@echo -e "\033[1;95mRunning tests...\033[0;39m"
		@gcc -o $(TEST_NAME) $(_SRC) $(TEST_SRC) $(CFLAGS) --coverage -lcriterion
		./$(TEST_NAME)
		gcovr
		@echo -e "\033[1;94mTest finished, here are the results\033[0;39m"
