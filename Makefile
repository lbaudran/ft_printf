NAME		=	libftprintf.a

FLAGS		=	-Wall -Wextra -Werror

SRC_C		=	*.c libft/*.c

SRC_O		= *.o

all: $(NAME)

$(NAME):
	gcc -c $(SRC_C)
	ar r $(NAME) $(SRC_O)
	ranlib $(NAME)


clean:
	rm -f $(SRC_O)
fclean:		clean
	rm -f $(NAME)

re: fclean all
