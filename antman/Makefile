##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## project's Makefile
##

SRC	=	$(wildcard ./src/*.c)

TESTS	=	$(wildcard ./tests/*.c)

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include -I../include -g3

LIB	=	-L../lib/my -lmy

NAME	=	antman

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) main.c $(OBJ) $(CFLAGS) $(LIB) -g3 -Werror -Wall -pedantic
	@make clean

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)
	@rm -f antman_tests-*
	@rm -f antman_tests

re:	fclean all

unit_tests:	fclean $(NAME)
	gcc -o antman_tests $(TESTS) $(SRC) $(LIB) $(CFLAGS) --coverage -lcriterion

tests_run:	unit_tests
	./antman_tests
