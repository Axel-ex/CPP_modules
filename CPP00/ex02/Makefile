NAME		= transactions

OBJ_DIR		= bin

SRC			= $(wildcard *.cpp)

OBJ			= $(SRC:.cpp=.o)

FLAGS		= -Wall -Wextra -Werror -std=c++98

GREEN		= \033[38;5;47m
YELLOW		= \033[38;5;226m
RED			= \033[38;5;196m
RESET 		= \033[0m

%.o: %.cpp
	@c++ $(FLAGS) -g -c $< -o $@
	@echo "[$(GREEN)compiling$(RESET)]: $<"

all: $(NAME)
	@echo "$(GREEN)$(NAME) executable created$(RESET)"

$(NAME): $(OBJ)
	@c++ $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ)
	@echo "$(YELLOW)Removing $(NAME) objects files$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)removing $(NAME) executable$(RESET)"

re: fclean all

.PHONY: all clean fclean re