# CC = cc
# CFLAGS = -g -Wall -Wextra -Werror
# SAN =  -g -O0 -fno-omit-frame-pointer -fsanitize=address 

NAME = MST.a
CONFIG_DIR = config
DEBUG_DIR = debug
UTILS_DIR = $(CONFIG_DIR)/utils

SRC = \
	start_game.c\
	$(CONFIG_DIR)/ft_config.c\
	$(DEBUG_DIR)/ft_debug.c\
	$(CONFIG_DIR)/ft_map.c\
	$(CONFIG_DIR)/ft_player.c\
	$(CONFIG_DIR)/ft_error.c\
	$(CONFIG_DIR)/ft_texturse.c\
	$(CONFIG_DIR)/ft_color.c\
	$(CONFIG_DIR)/ft_file.c\
	$(CONFIG_DIR)/ft_init_game.c\
	$(UTILS_DIR)/ft_utils1.c\
	$(UTILS_DIR)/ft_utils2.c\
	$(UTILS_DIR)/ft_tools1.c\
	$(UTILS_DIR)/ft_tools2.c\
	$(UTILS_DIR)/ft_tools4.c\
	$(UTILS_DIR)/ft_utils3.c\
	$(UTILS_DIR)/ft_tools3.c\
	$(UTILS_DIR)/ft_utils4.c\
	$(UTILS_DIR)/ft_utils5.c\

OBJ = $(SRC:.c=.o)

all: $(NAME) $(LIBFT_LIB)


$(NAME): $(OBJ)
	@ar csr $(NAME) $(OBJ)
# $(NAME): $(OBJ) $(LIBFT_LIB)
# 	@$(CC) $(CFLAGS) $(SAN) $(OBJ) $(LIBFT_LIB) -o $(NAME) 

clean:
	@rm -f $(OBJ)

fclean:clean
	@rm -f $(NAME)

re:fclean all

.PHONY: clean all fclean re
