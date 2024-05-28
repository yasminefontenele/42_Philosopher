# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 15:41:03 by yfontene          #+#    #+#              #
#    Updated: 2024/05/27 06:55:18 by yasmine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


GREEN				=	\033[0;32m
RED					=	\033[0;31m
YELLOW				=	\033[0;33m
END					=	\033[0m

NAME	=	philo

HEADER	= 	philo.h
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

SRCS	=	philo_run.c \
			utils.c \
			str_utils.c \
			init.c \
			philosophers.c \
			threads.c

OBJS	=	$(SRCS:%.c=%.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) $(HEADER) -o $(NAME)
			@echo "$(GREEN)Philosophers succesfully compiled!$(END)"

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
			@echo "Compiling $<."

clean:
			@$(RM) $(OBJS)
			
fclean:		clean
			@$(RM) $(NAME)
			@echo "$(RED)Philosophers deleted!$(END)"

re:			fclean all

.PHONY:		all clean fclean re