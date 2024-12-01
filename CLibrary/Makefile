##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Compiles your libmy
##

SRC	=	my_hash.c 					\
		my_radix.c 					\

.SILENT:
OBJ	= $(SRC:.c=.o)

NAME	= libmy.a

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc libmy.a $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../libmy.a
	rm -f $(NAME)

re: 	fclean $(NAME)