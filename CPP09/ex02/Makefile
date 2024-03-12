NAME		= PmergeMe

OBJ_DIR		= bin

SRC_DIR		= sources

SRC			= $(wildcard $(SRC_DIR)/*.cpp)

OBJ			= $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

FLAGS		= -Wall -Wextra -Werror -std=c++98 -O3

INC			= includes/

GREEN		= \033[38;5;47m
YELLOW		= \033[38;5;226m
RED			= \033[38;5;196m
RESET 		= \033[0m

MODE		= none

ifeq ($(MODE), debug)
    FLAGS += -D DEBUG
endif

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@c++ $(FLAGS) -g -c $< -o $@
	@echo "[$(GREEN)compiling$(RESET)]: $<"

all: $(NAME)
	@echo "$(GREEN)$(NAME) executable created$(RESET)"

$(OBJ_DIR):
	@mkdir bin/

$(NAME): $(OBJ)
	@c++ $(FLAGS) -I $(INC) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)Removing $(NAME) objects files$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)removing $(NAME) executable$(RESET)"

re: fclean all

.PHONY: all clean fclean re
