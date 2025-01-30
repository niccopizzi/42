CFLAGS =  -g -Wall -Wextra -Werror

NAME = fractol

LIB = -L./libs/minilibx-linux -lmlx_Linux -L./libs/libft -lft -L./libs/ft_printf -lftprintf  -lX11 -lXext -lm  

LIBFT_PATH = ./libs/libft/
LIBFT = $(LIBFT_PATH)libft.a

PRINTF_PATH = ./libs/ft_printf/
PRINTF = $(PRINTF_PATH)libftprintf.a

MLX = ./libs/minilibx-linux/libmlx_Linux.a

MY_SOURCES = ./sources/init.c \
			./sources/hooks.c \
			./sources/utils.c \
			./sources/valid_checker.c \
			./fractals/burning_ship.c \
			./fractals/julia.c \
			./fractals/mandelbrot.c \
			./fractals/palette.c

all: $(NAME)

$(LIBFT):
	@make -s -C ./libs/libft bonus

$(PRINTF):
	@make -s -C ./libs/ft_printf

$(MLX):
	@make -s -C ./libs/minilibx-linux 

$(NAME): $(MY_SOURCES) $(LIBFT) $(MLX) $(PRINTF)
	@cc $(CFLAGS) $(MY_SOURCES) -o $(NAME) $(LIB)
	@echo "... Amazing! I managed to compile fractol"

%.o :%.c
	@cc $(CFLAGS) -g -c $< -o $@ 
	@echo "$< compiled."
	
clean:
	@make -s -C $(LIBFT_PATH) clean
	@make -s -C $(PRINTF_PATH) clean
	@$(RM) $(MY_OBJECTS)
	@echo "Objects files removed."

fclean: clean
	@make -s -C $(LIBFT_PATH) fclean
	@make -s -C $(PRINTF_PATH) fclean
	@$(RM) $(NAME)
	@echo "$(NAME) removed."

re: fclean all

.PHONY: all clean fclean re bonus