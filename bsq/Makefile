# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 19:33:10 by mgama             #+#    #+#              #
#    Updated: 2024/02/06 17:54:52 by mgama            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_DIR			=	.objs
SRCS_DIR		=	sources

SRCS			=	$(SRCS_DIR)/ft_split.c \
					$(SRCS_DIR)/parsing_utils.c \
					$(SRCS_DIR)/solver.c \
					$(SRCS_DIR)/main.c \
					$(SRCS_DIR)/parsing_utils2.c \
					$(SRCS_DIR)/parsing.c \
					$(SRCS_DIR)/printer.c \
					$(SRCS_DIR)/read_file.c
OBJS			=	$(patsubst $(SRCS_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

HEADERS_DIR		=	includes/
HEADERS			=	$(HEADERS_DIR)/functions.h	\
					$(HEADERS_DIR)/parsing.h \
					$(HEADERS_DIR)/structs.h

RM				=	rm -f
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -I $(HEADERS_DIR)
NAME			=	bsq

GREEN			=	\033[1;32m
BLUE			=	\033[1;34m
RED				=	\033[1;31m
YELLOW			=	\033[1;33m
DEFAULT			=	\033[0m
UP				=	"\033[A"
CUT				=	"\033[K"

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS) Makefile
	@mkdir -p $(@D)
	@echo "$(YELLOW)Compiling [$<]$(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf ${UP}${CUT}

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(DEFAULT)"

clean:
	@echo "$(RED)Cleaning build folder$(DEFAULT)"
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Cleaning $(NAME)$(DEFAULT)"
	@$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus