CC			=	gcc
CFILES		=	srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c 
HEADERS_DIR	=	includes/
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	libft.a
OBJS		=	${CFILES:.c=.o}
LIBC		=	ar rc
LIBR		=	ranlib

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I $(HEADERS_DIR)

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	${LIBR} ${NAME}

all: ${NAME}

clean:
	rm -rf srcs/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re .c.o