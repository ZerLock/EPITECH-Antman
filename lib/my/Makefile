##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## lib's Makefile
##

SRC	=	my_getnbr.c	\
		my_put_nbr.c	\
		my_putchar.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_strdup.c	\
		my_strlen.c	\
		my_strcat.c \
		my_strcmp.c \
		read_file.c \
		error_handling.c \
		int_to_base.c \
		add_to_buffer.c \
		my_putnbr_base.c	\
		my_printf/my_printf_exec_flags.c	\
		my_printf/my_printf_fid.c	\
		my_printf/my_printf_functions.c	\
		my_printf/my_printf_get_opt.c	\
		my_printf/my_printf_handle_flags.c	\
		my_printf/my_printf_main.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	make clean

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

