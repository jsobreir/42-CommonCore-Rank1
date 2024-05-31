LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = mlx_linux
MLX = $(MLX_DIR)/libmlx_Linux.a
SRC = fractol.c init.c render.c events.c
OBJ = $(SRC:.c=.o)
NAME = fractol
FLAGS = -g -Wall -Wextra -Werror -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz
CC = cc
HEADER = fractol.h

all: $(NAME)

$(NAME): $(OBJ) $(MLX) $(LIBFT)
	$(CC) $(OBJ) -o $(NAME) $(FLAGS) -L$(LIBFT_DIR) -lft

# Compile each c file into o file (-o specifies name of output file, -c tells compiler to compile src file into obj but not to link it)
# -03 is to enable optimization during compilation
%.o: %.c $(HEADER)
	$(CC) -Wall -Wextra -Werror -I/usr/include -I$(MLX_DIR) -O3 -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re