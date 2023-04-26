# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 09:22:41 by maricard          #+#    #+#              #
#    Updated: 2023/04/26 19:02:11 by maricard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Werror -Wextra
RM = rm -rf

NAME = philo
INCLUDES = includes

SRC =	./utils/ft_atoi.c \
		./utils/ft_bzero.c \
		./utils/args.c \
		./utils/tests.c \
		./utils/print.c \
		./src/threads.c  \
		./src/values.c \
		./src/forks_checker.c \
		./src/time.c \
		./src/sleep.c \
		./src/think.c

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
