#include "include/cub3d.h"
#include "mlx.h"

void load_texturse(t_game *game, t_texturse *txt)
{
    t_texturse *t = game->txt;

    t->img_no = mlx_xpm_file_to_image(game->mlx, txt->no, &t->width, &t->height);
    t->img_so = mlx_xpm_file_to_image(game->mlx, txt->so, &t->width, &t->height);
    t->img_we = mlx_xpm_file_to_image(game->mlx, txt->we, &t->width, &t->height);
    t->img_ea = mlx_xpm_file_to_image(game->mlx, txt->ea, &t->width, &t->height);
    if (!t->img_no || !t->img_so || !t->img_we || !t->img_ea)
    {
        error("Texture not found");
        ft_malloc(0, 0);
        exit(0);
    }
}

int main(int argc,char *argv[])
{
    t_game *game;

    game = malloc(sizeof(t_game));
    if (!start(argc,argv,game))
        return (0);
    free(game);
    return (1);
}
