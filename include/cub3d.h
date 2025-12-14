#ifndef CUB3D_H
# define CUB3D_H

#include "../parsing/include/parsing.h"
#include "../parsing/libft/libft.h"
#include "../parsing/config/config.h"

typedef struct  s_game
{
	t_cub *cub; //Usage (t_game *game)
				//game->cub->grid
				//game->cub->f_color
				//game->cub->c_color
				//game->cub->width
				//...
    t_texturse *txt;//Usage (t_game *game)
				//game->txt->no_image
				//game->txt->so_image
				//game->txt->we_image
				//game->txt->ea_image
	void *mlx;
	void *win;
}t_game;
int	start(int ac, char **args,t_game *game);
#endif