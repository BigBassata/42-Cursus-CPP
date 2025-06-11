# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: licohen <licohen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 14:03:28 by licohen           #+#    #+#              #
#    Updated: 2025/05/22 17:43:46 by licohen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook
CPP = g++
OBJ_FOLDER = obj
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Contact.cpp PhoneBook.cpp
OBJS = $(SRCS:%.cpp=$(OBJ_FOLDER)/%.o)
HEADERS = Contact.hpp PhoneBook.hpp

all: $(OBJ_FOLDER) $(NAME)

$(OBJ_FOLDER):
	mkdir -p $(OBJ_FOLDER)

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJ_FOLDER)/%.o: %.cpp $(HEADERS)
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_FOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re