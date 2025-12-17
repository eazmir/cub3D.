#include "include/cub3d.h"
#include "mlx.h"

void init_textures(t_game *game)
{
    t_texturse *t = game->txt;

    t->img_no = mlx_xpm_file_to_image(game->mlx, t->no, &t->width, &t->height);
    t->img_so = mlx_xpm_file_to_image(game->mlx, t->so, &t->width, &t->height);
    t->img_we = mlx_xpm_file_to_image(game->mlx, t->we, &t->width, &t->height);
    t->img_ea = mlx_xpm_file_to_image(game->mlx, t->ea, &t->width, &t->height);
    if (!t->img_no || !t->img_so || !t->img_we || !t->img_ea)
    {
        error("Texture not found");
        ft_malloc(0, 0);
        exit(0);
    }
}

void test_texture(t_game *game)
{
    void *win;

    win = mlx_new_window(game->mlx, 400, 400, "Texture test");
    mlx_put_image_to_window(game->mlx, win,game->txt->img_so, 0, 0);
    mlx_loop(game->mlx);
}

int main(int argc, char *argv[])
{
    t_game *game;

    game = malloc(sizeof(t_game));
    if (!game)
        return (0);
    game->mlx = mlx_init();
    if (!game->mlx)
        return (0);
    if (!start(argc, argv, game))
        return (0);
    init_textures(game);
    printf("|--------------------------test-----------------------------------|");
    test_texture(game);
    printf("--------test---------->%d\n",game->txt->width);
    printf("----------test-------->%d\n",game->txt->height);
    printf("-----------test-------->%p\n", game->txt->img_ea);
    free(game);
    return (1);
}

