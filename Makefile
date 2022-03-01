##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## project's Makefile
##

NAME	=	compile

all:	$(NAME)

$(NAME):
	@echo -e "\033[0;36mCompile library..."
	@make -s -C lib/my
	@echo -e "Library compiled !\n"
	@echo -e "\033[0;32mCompile antman..."
	@make -s -C antman
	@echo -e "Antman compiled !\n"
	@echo -e "\033[0;31mCompile giantman..."
	@make -s -C giantman
	@echo -e "Giantman compiled !\033[0m"

clean:
	@echo -e "\033[0;36mClean library..."
	@make clean -C lib/my > /dev/null
	@echo -e "Removed all .o files in library !\n"
	@echo -e "\033[0;32mClean antman..."
	@make clean -C antman/ > /dev/null
	@echo -e "Removed all .o files in antman !\n"
	@echo -e "\033[0;31mClean giantman..."
	@make clean -C giantman/ > /dev/null
	@echo -e "Removed all .o files in giantman !\033[0m\n"

fclean:	clean
	@make fclean -C lib/my > /dev/null
	@make fclean -C antman/ > /dev/null
	@make fclean -C giantman/ > /dev/null

re:	fclean all

unit_tests:	fclean $(NAME)
	make unit_tests -C antman
	make unit_tests -C giantman

tests_run:	unit_tests
	make tests_run -C antman
	make tests_run -C giantman
