##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC		=	src/main.c	\
			src/args/check_args.c	\
			src/generator/generation.c	\
			src/generator/binary_tree.c	\
			src/display.c	\
			src/generator/not_perfect.c	\

OBJ		=	$(SRC:.c=.o)

INC_DIR		=	$(realpath ./include)

NAME		=	generator

CFLAGS		=	-W -Wall -Wextra -pedantic -g3 -I$(INC_DIR)


all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

tests_run:
		make tests_run -C ./tests

tests_coverage:	tests_run
		lcov --directory ./tests -c -o rapport.info &>/dev/null
		genhtml -o ./bonus/cov_report -t "code coverage report" rapport.info &>/dev/null
		xdg-open ./bonus/cov_report/src/index.html &>/dev/null

.PHONY: all clean fclean re tests_run tests_coverage
