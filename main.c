/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:36:03 by eazmir            #+#    #+#             */
/*   Updated: 2025/09/11 14:50:41 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"
#include "mlx.h"

void load_texturse(t_cub *game,t_texturse *txt)
{

	game->txt.img_no = mlx_xpm_file_to_image(game->mlx, txt->no, &game->txt.width, &game->txt.height);
	game->txt.img_so = mlx_xpm_file_to_image(game->mlx, txt->so, &game->txt.width, &game->txt.height);
	game->txt.img_we = mlx_xpm_file_to_image(game->mlx, txt->we, &game->txt.width, &game->txt.height);
	game->txt.img_ea = mlx_xpm_file_to_image(game->mlx, txt->ea, &game->txt.width, &game->txt.height);
	if (!game->txt.img_no || !game->txt.img_so || !game->txt.img_we || !game->txt.img_ea)
	{
		error("Texturse not found");
		ft_malloc(0,0);
		exit(0);
	}
}

int main(int ac,char **args)
{ 

	t_cub		*game;
	t_texturse	*txt;
	if (ac != 2)
	{
    	printf("Usage: ./cub <map_file.cub>\n");
    	return (1);
	}
	if (!init_game(&game, &txt, args[1]))
	{
		ft_malloc(0,0);
		return (1);
	}
    game->mlx = mlx_init();
	load_texturse(game,txt);
    game->win = mlx_new_window(game->mlx, 600, 800, "Hello MLX");
	mlx_put_image_to_window(game->mlx, game->win, game->txt.img_no, 0, 0);      // top-left
    mlx_put_image_to_window(game->mlx, game->win, game->txt.img_so, game->txt.width, 0);      // top-right
    mlx_put_image_to_window(game->mlx, game->win, game->txt.img_we, 0, game->txt.height);      // bottom-left
    mlx_put_image_to_window(game->mlx, game->win, game->txt.img_ea, game->txt.width, game->txt.height);      // bottom-right
    mlx_loop(game->mlx);
	// debug_game(game, txt);
    return 0;
}