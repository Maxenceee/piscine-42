CC				=	cc
CFILES			=	ft_display_file.c
HEADERS_DIR		=	includes/
CFLAGS			=	-Wall -Wextra -Werror -I $(HEADERS_DIR)
NAME			=	ft_display_file
OBJS			=	${CFILES:.c=.o}

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf ft_display_file.o

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re