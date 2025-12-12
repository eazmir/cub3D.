# CC = cc
# CFLAGS = -g -Wall -Wextra -Werror

CFLAGS = -g  -Wall -Wextra -Werror
# SAN =  -g -O0 -fno-omit-frame-pointer -fsanitize=address
NAME = cub
SRC = main.c
OBJ = $(SRC:.c=.o)

MLX = ./mlx
MFLAGS = -lmlx -lX11 -lXext -lm -lz 
PARS_DIR = parsing
MLX_LIB = $(MLX)/libmlx_Linux.a
LIBFT_DIR = $(PARS_DIR)/libft
PARS_LIB = $(PARS_DIR)/MST.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

$(PARS_LIB):
	@make -C $(PARS_DIR)

$(MLX_LIB):
	@make -C $(MLX)

all: $(NAME) $(LIBFT_LIB) $(PARS_LIB) $(MLX_LIB)

$(NAME): $(OBJ) $(LIBFT_LIB) $(PARS_LIB) $(MLX_LIB)
	@$(CC) $(CFLAGS) $(SAN) $(OBJ) $(PARS_LIB) $(MLX_LIB) $(MFLAGS) $(LIBFT_LIB) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@make -C $(PARS_DIR) clean
	@make -C $(LIBFT_DIR) clean

fclean:clean
	@rm -f $(NAME)
	@make -C $(PARS_DIR) fclean
	@make -C $(LIBFT_DIR) fclean

re:fclean all

.PHONY: clean all fclean re
