SRC_PATH = SRC

OBJ_PATH = obj

SRC_NAME = apply_diez.c \
		   apply_diez_2.c \
		   arg_forscient.c \
		   check.c \
		   check_type.c \
		   fill_point.c \
		   ft_convertbase.c \
		   ft_dtoa.c \
		   ft_printf.c \
		   ft_utoa.c \
		   get_arg.c \
		   get_arg_2.c \
		   get_arg_3.c \
		   init_pt_tab.c \
		   is_forprintf.c \
		   print_arg.c \
		   get_int.c \
		   get_int_2.c \
		   get_unsigned.c \
		   get_unsigned_2.c \
		   get_nothing.c \
		   ft_wstr.c \


LIBFT_NAME = ft_strcpy.c \
			 ft_strcat.c \
			 ft_memmove.c \
			 ft_strchr.c \
			 ft_bzero.c \
			 ft_isdigit.c \
			 ft_atoi.c \
			 ft_toupper.c \
			 ft_power.c \
			 ft_strlen.c \
			 ft_itoa.c \
			 ft_strncpy.c \
			 ft_round.c \
			 ft_memcpy.c \

LIBFT_PATH = libft

OBJLIBFT_PATH = objlibft

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJLIBFT_NAME = $(LIBFT_NAME:.c=.o)

NAME = libftprintf.a

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJLIBFT = $(addprefix $(OBJLIBFT_PATH)/,$(OBJLIBFT_NAME))
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
LIBFT = $(addprefix $(LIBFT_PATH)/,$(LIBFT_NAME))

all : $(NAME)

$(NAME) : $(OBJ) $(OBJLIBFT)
	ar r $(NAME) $(OBJ) $(OBJLIBFT)
	ranlib -a $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	clang -o $@ -c $<

$(OBJLIBFT_PATH)/%.o : $(LIBFT_PATH)/%.c
	@mkdir $(OBJLIBFT_PATH) 2> /dev/null || true
	clang -o $@ -c $<

clean :
	rm -fv $(OBJ)
	rm -fv $(OBJLIBFT)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@rmdir $(OBJLIBFT_PATH) 2> /dev/null || true

fclean : clean
	rm -fv $(NAME)

re : fclean all

.PHONY : all, clean, fcleann, re
