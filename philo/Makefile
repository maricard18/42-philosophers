# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maricard <maricard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 09:22:41 by maricard          #+#    #+#              #
#    Updated: 2023/04/25 17:12:35 by maricard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

NAME = philo
INCLUDES = includes

SRC =	./utils/ft_atoi.c \
		./utils/ft_bzero.c \
		./utils/args.c \
		./utils/tests.c \
		./utils/linked_list.c \
		./src/threads.c 

SRC-OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC-OBJ) $(LIBFT)
	$(CC) -pthread $(CFLAGS) main.c $(SRC-OBJ) -o $(NAME) -I $(INCLUDES)

%.o: %.c
	$(CC) -pthread $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
	$(RM) $(SRC-OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
