CFLAGS = -Warray-bounds -msse2 -march=native -mavx2 -O2 -I./include
SQUARE = -D IMG_RATIO=1
NAME = miniRT

LIBFT_DIR = ./lib/minift
LIB = -L./lib/minilibx-linux -lmlx_Linux -L./lib/minift -lminift -lX11 -lXext -lm  

MY_SOURCES = ./src/main.c \
				./src/*/*

all: $(NAME)

$(NAME): $(MY_SOURCES)
	@make -C $(LIBFT_DIR)
	@gcc $(CFLAGS) $(MY_SOURCES) $(LIB) -o $(NAME) 
	@echo "... Amazing! I managed to compile $(NAME)"

%.o :%.c
	@gcc $(CFLAGS) -g -c $< -o $@ 
	@echo "$< compiled."


square: 
	@gcc $(CFLAGS) $(SQUARE) $(MY_SOURCES) $(LIB) -o $(NAME)
	@echo "COMPILED THE SQUARED MOTAFAKKA!"
	
clean:
	@$(RM) $(MY_OBJECTS)
	@echo "Objects files removed."

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) removed."

re: fclean all
