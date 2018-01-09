# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aparabos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 12:15:46 by aparabos          #+#    #+#              #
#    Updated: 2017/11/22 14:44:06 by aparabos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = rm -rf
NAME = fillit
FLAGS = -Wall -Werror -Wextra
SRCS = ft_basic.c ft_basic2.c ft_changechar.c ft_check.c ft_coord.c \
	   ft_lstbasic.c ft_lststock.c ft_mapgen.c ft_putpieces.c \
	   ft_storage.c main.c mapgenfc.c

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean

all: $(NAME)

$(NAME): $(OBJS)
		@$(CC) -c $(FLAGS) $(SRCS)
		
		@$(CC) -o $(NAME) $(OBJS)

clean:
		@$(RM) $(OBJS)

fclean: clean
		@$(RM) $(NAME)

re: fclean all
