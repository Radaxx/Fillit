# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aparabos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 12:15:46 by aparabos          #+#    #+#              #
#    Updated: 2017/11/13 15:06:33 by aparabos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = rm -rf
NAME = fillit
FLAGS = -Wall -Werror -Wextra
SRCS = *.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean

all: $(NAME)

$(NAME):
		$(CC) -c $(FLAGS) $(SRCS)
		$(CC) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all
