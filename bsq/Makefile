CC=gcc
CFILES=$(shell find srcs -type f -name "*.c")
HEADERS_DIR=includes/
CFLAGS=-Wall -Wextra -Werror -I $(HEADERS_DIR)
NAME=bsq
OBJS=${CFILES:.c=.o}

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf srcs/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re