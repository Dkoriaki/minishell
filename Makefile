# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkoriaki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/12 09:08:21 by dkoriaki          #+#    #+#              #
#    Updated: 2021/08/12 09:08:23 by dkoriaki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

SRCS	=	./srcs/cd.c \
				./srcs/echo.c \
				./srcs/env.c \
				./srcs/exec_bin.c \
				./srcs/exit.c \
				./srcs/export.c \
				./srcs/get_next_line.c \
				./srcs/get_next_line_utils.c \
				./srcs/main.c \
				./srcs/split.c \
				./srcs/unset.c \
				./srcs/utils.c

OBJS		=	$(SRCS:.c=.o)

INCLUDES	=	./includes

CC			=	gcc -g3 -fsanitize=address

CFLAGS		=	-Wall -Wextra -Werror

HEAD		=	-I$(INCLUDES)

all:			$(NAME)

%.o: %.c 
	@printf "\033[0;33mGenerating minishell objects... %-33.33s\r" $@
	@$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

$(NAME)	:	$(OBJS)
	@echo "\n"
	@echo "\033[0;32mCompiling minishell..."
	@$(CC) $(OBJS) $(HEAD) $(CFLAGS) -o $@
	@echo "\n\033[0mDone !"

clean :
	@echo "\nDeleting objects..."		
	@rm -f $(OBJS)
	@echo "\033[0m"

fclean :	clean
	@echo "\nDeleting executable..."
	@rm -f $(NAME)
	@echo "\033[0m"

re :		fclean all

.PHONY: all clean fclean re
