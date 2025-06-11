NAME = Zombie
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Zombie.cpp randomChump.cpp newZombie.cpp
OBJDIR = obj
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re