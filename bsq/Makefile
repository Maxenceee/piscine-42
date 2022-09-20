CC			=	gcc
CFILES		=	srcs/ft_split.c srcs/parsing_utils.c srcs/solver.c srcs/main.c srcs/parsing_utils2.c srcs/parsing.c srcs/printer.c
HEADERS_DIR	=	includes/
CFLAGS		=	-Wall -Wextra -Werror -I $(HEADERS_DIR)
NAME		=	bsq
OBJS		=	${CFILES:.c=.o}

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)
