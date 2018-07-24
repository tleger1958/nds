NAME=bsq
SRC=src/main.c \
	src/bsq.c \
	src/stream.c \
	src/solve.c \
	src/utilities.c
LIBFT=libft/ft_array_size.c \
	libft/ft_putchar.c \
	libft/ft_putstr.c \
	libft/ft_strlen.c \
	libft/ft_atoi.c

all:
	gcc -Wall -Wextra $(SRC) $(LIBFT) -o $(NAME)

clean:
	/bin/rm -f $(NAME)

re: clean all
