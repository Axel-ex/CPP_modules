NAME	=	megaphone

SRC		=	megaphone.cpp

CC		=	c++

FLAGS	=	-Wall -Wextra -Werror -std=c++98 -fsanitize=address

$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $@

all: $(NAME)

clean:
	rm -rf $(NAME)

re: clean all

.PHONY: all clean re
