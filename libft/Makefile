# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbaudran <lbaudran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/26 14:36:52 by jelefebv          #+#    #+#              #
#    Updated: 2015/12/22 16:35:34 by lbaudran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

SRC_C		=	ft_atoi.c\
ft_bzero.c\
ft_memset.c\
ft_memcpy.c\
ft_memccpy.c\
ft_memchr.c\
ft_memcmp.c\
ft_memmove.c\
ft_strlen.c\
ft_strdup.c\
ft_strcpy.c\
ft_strncpy.c\
ft_strcat.c\
ft_strlcat.c\
ft_strncat.c\
ft_strchr.c\
ft_strrchr.c\
ft_strstr.c\
ft_strnstr.c\
ft_strcmp.c\
ft_strncmp.c\
ft_isalpha.c\
ft_isdigit.c\
ft_isalnum.c\
ft_isascii.c\
ft_isprint.c\
ft_toupper.c\
ft_tolower.c\
ft_memalloc.c\
ft_memdel.c\
ft_strnew.c\
ft_strdel.c\
ft_strclr.c\
ft_striter.c\
ft_striteri.c\
ft_strmap.c\
ft_strmapi.c\
ft_strequ.c\
ft_strnequ.c\
ft_strsub.c\
ft_strjoin.c\
ft_strtrim.c\
ft_strsplit.c\
ft_itoa.c\
ft_putchar.c\
ft_putstr.c\
ft_putendl.c\
ft_putnbr.c\
ft_putchar_fd.c\
ft_putstr_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_min.c\
ft_max.c\
ft_swap.c\
ft_islower.c\
ft_isupper.c\
ft_power.c\
ft_realloc_str.c

SRC_O		=	$(SRC_C:.c=.o)

all:		$(NAME)

$(NAME): $(SRC_O)
	printf "\r\033[38;5;11m⌛  MAKE   $(NAMEBASE) plz wait ...\033[0m\033[K"
	ar rc $(NAME) $(SRC_O)
	ranlib $(NAME)
	echo "\r\033[38;5;184m👥  GROUP MEMBER(S):\033[0m\033[K"
	echo "\r\033[38;5;15m`cat auteur | sed s/^/\ \ \ \ -/g`\033[0m\033[K"

clean:
	printf "\r\033[38;5;11m⌛  CLEAN  $(NAMEBASE) plz wait ...\033[0m\033[K"
	rm -f $(SRC_O)
	printf "\r\033[38;5;11m☑️  CLEAN  $(NAMEBASE) is done\033[0m\033[K"

fclean:		clean
	printf "\r\033[38;5;11m⌛  FCLEAN $(NAMEBASE) plz wait ...\033[0m\033[K"
	rm -f $(NAME)
	printf "\r\033[38;5;11m☑️  FCLEAN  $(NAMEBASE) is done\033[0m\033[K"

re:			fclean all

.PHONY:		fclean clean re
