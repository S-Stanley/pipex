# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 20:55:26 by sserbin           #+#    #+#              #
#    Updated: 2021/11/10 20:55:27 by sserbin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	main.c \
		src/clean.c src/error.c src/file.c src/get_cmd.c src/process.c \
		utils/count_occurence.c utils/ft_concat.c utils/ft_split.c utils/ft_strlen.c utils/push_arr.c utils/str_write.c utils/ft_strdup.c
OBJS = $(SRC:.c=.o)
NAME = pipex
CC = clang
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

re: clean all

fclean: clean
	$(RM) $(NAME)

.PHONY: all clean re fclean