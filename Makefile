NAME=bsq
SRC=src/*.c
LIBFT=libft/*.c

all:
	gcc -Wall -Wextra $(SRC) $(LIBFT) -o $(NAME)

clean:
	/bin/rm -f $(NAME)

re: clean all
