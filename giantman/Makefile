##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## project's Makefile
##

SRC	=	$(wildcard ./src/*.c)

TESTS	=	$(wildcard ./tests/*.c)

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include -g3

LIB	=	-L../lib/my -lmy

NAME	=	giantman

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) main.c $(OBJ) $(CFLAGS) $(LIB) -g3
	@make clean

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)
	@rm -f giantman_tests-*
	@rm -f giantman_tests

re:	fclean all

unit_tests:	fclean $(NAME)
	gcc -o giantman_tests $(TESTS) $(SRC) $(CFLAGS) $(LIB) --coverage -lcriterion

tests_run:	unit_tests
	./giantman_tests
