#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmikaeli <bmikaeli@student.42.fr>           +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 12:12:12 by bmikaeli          #+#    #+#              #
#    Updated: 2015/01/05 12:12:12 by bmikaeli         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: clean fclean re

NAME = megaphone

CC = g++ $(FLAGS)

FLAGS = -Wall -Wextra -Werror

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIB)

%.o: %.c %.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
