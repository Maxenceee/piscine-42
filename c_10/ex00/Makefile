CC=cc
CFILES=$(shell find . -type f -name "*.c")
HEADERS_DIR=includes/
CFLAGS=-Wall -Wextra -Werror -I $(HEADERS_DIR)
NAME=ft_display_file
OBJS=${CFILES:.c=.o}

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf sources/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re