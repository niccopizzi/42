CXX = c++
CXXFLAGS = -Wall -Wextra -std=c++98 $(INCLUDE)
OBJ_DIR = obj/
SRC_DIR = src/
SRC =		$(SRC_DIR)main.cpp	\
			$(SRC_DIR)connection/Server1.cpp 			\
			$(SRC_DIR)connection/Server2.cpp			\
			$(SRC_DIR)connection/Listener.cpp 			\
			$(SRC_DIR)connection/ClientConnection.cpp	\
			$(SRC_DIR)parsing/Tokenizer.cpp				\
			$(SRC_DIR)parsing/Token.cpp

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
INCLUDE = -Iinclude


NAME = webserv

all: $(NAME)

$(NAME): $(OBJ)
	@echo ""${BLUE}$(NAME)""${NC} Compiling... "\c"
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo ""${GREEN}Complete""$(NC)""

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

WHITE	=	'\033[0;37m'
YELLOW	=	'\033[0;33m'
BLUE	=	'\033[0;34m'
GREEN	=	'\033[0;32m'
RED		=	'\033[0;31m'
NC		=	'\033[0m'

	
debug: CXXFLAGS += -DDEBUG
debug: re

clean:
	@rm -rf $(OBJ_DIR)
	@echo ""${GREEN}Clean Complete""$(NC)""
fclean: clean
	@rm -f $(NAME)
	@echo ""${GREEN}Fclean Complete""$(NC)""

re: fclean all

.PHONY: all clean fclean re