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
#include "mlx.h"
#include "parsing/debug/debug.h"

void	destroy(t_cub *game)
{
	if (!game || !game->mlx)
		return ;
	if (game->txt.img_no)
		mlx_destroy_image(game->mlx, game->txt.img_no);
	if (game->txt.img_so)
		mlx_destroy_image(game->mlx, game->txt.img_so);
	if (game->txt.img_we)
		mlx_destroy_image(game->mlx, game->txt.img_we);
	if (game->txt.img_ea)
		mlx_destroy_image(game->mlx, game->txt.img_ea);
}

void	load_texturse(t_cub *game, t_texturse *txt)
{
	game->txt.img_no = mlx_xpm_file_to_image(game->mlx, txt->no,
			&game->txt.width, &game->txt.height);
	if (!game->txt.img_no)
		game->txt.img_no = NULL;
	game->txt.img_so = mlx_xpm_file_to_image(game->mlx, txt->so,
			&game->txt.width, &game->txt.height);
	if (!game->txt.img_so)
		game->txt.img_so = NULL;
	game->txt.img_we = mlx_xpm_file_to_image(game->mlx, txt->we,
			&game->txt.width, &game->txt.height);
	if (!game->txt.img_we)
		game->txt.img_we = NULL;
	game->txt.img_ea = mlx_xpm_file_to_image(game->mlx, txt->ea,
			&game->txt.width, &game->txt.height);
	if (!game->txt.img_ea)
		game->txt.img_ea = NULL;
	if (!game->txt.img_no || !game->txt.img_so || !game->txt.img_we
		|| !game->txt.img_ea)
	{
		error("Texturse not found");
		ft_malloc(0, 0);
		exit(0);
	}
}

int	main(int ac, char **args)
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
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	debug_game(game, txt);
	return (0);
}