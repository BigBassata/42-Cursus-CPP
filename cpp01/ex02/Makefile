NAME = this_is_brain
CXX = c++
OBJ_FOLDER = obj
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp
OBJS = $(SRCS:%.cpp=$(OBJ_FOLDER)/%.o)

all: $(OBJ_FOLDER) $(NAME)

$(OBJ_FOLDER):
	mkdir -p $(OBJ_FOLDER)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_FOLDER)/%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_FOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re