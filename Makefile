##
## EPITECH PROJECT, 2020
## Makefiçle plazza
## File description:
## Makefiçle plazza
##

SRC	=	trade.cpp

NAME	=	trade

all: $(NAME)

$(NAME):
	@g++ $(SRC) -g -w -o $(NAME) -Wall -Wextra -Werror

clean:
	@rm -f $(NAME)

fclean:
	@rm -f $(NAME)

re:	fclean all