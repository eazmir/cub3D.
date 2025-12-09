/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:36:03 by eazmir            #+#    #+#             */
/*   Updated: 2025/12/09 22:41:02 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"
#include "parsing/debug/debug.h"

int main(int ac, char **args)
{

	t_cub *game;
	t_texturse *txt;
	if (ac != 2)
	{
		printf("Usage: ./cub <map_file.cub>\n");
		return (1);
	}
	if (!init_game(&game, &txt, args[1]))
	{
		ft_malloc(0, 0);
		return (1);
	}
	// game->mlx = mlx_init();
	debug_game(game, txt);
	// game->win = mlx_new_window(game->mlx, 600, 800, "Hello MLX");
	// mlx_put_image_to_window(game->mlx, game->win, game->txt.img_no, 0, 0);      // top-left
	// mlx_put_image_to_window(game->mlx, game->win, game->txt.img_so, game->txt.width, 0);      // top-right
	// mlx_put_image_to_window(game->mlx, game->win, game->txt.img_we, 0, game->txt.height);      // bottom-left
	// mlx_put_image_to_window(game->mlx, game->win, game->txt.img_ea, game->txt.width, game->txt.height);      // bottom-right
	// mlx_loop(game->mlx);
	return 0;
}