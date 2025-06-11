# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: licohen <licohen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/25 17:18:21 by licohen           #+#    #+#              #
#    Updated: 2025/05/22 17:43:51 by licohen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = megaphone.cpp
NAME = megaphone
OBJ = $(SRC:.cpp=.o)
FLAGS = -std=c++98 -Wall -Wextra -Werror
CC = g++

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re