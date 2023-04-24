# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maricard <maricard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 09:22:41 by maricard          #+#    #+#              #
#    Updated: 2023/03/27 10:31:06 by maricard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

NAME = philo
INCLUDES = includes

SRC = ./src/test.c

SRC-OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC-OBJ) $(LIBFT)
	$(CC) -pthread $(CFLAGS) $(SRC-OBJ) -o $(NAME) -I $(INCLUDES)

%.o: %.c
	$(CC) -pthread $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
	$(RM) $(SRC-OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
