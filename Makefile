all:
	gcc -Wall -Wextra -Werror *.c *.h

clean:
	rm *.o

fclean:
	rm a.out

re: fclean all
