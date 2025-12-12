/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:51:58 by eazmir            #+#    #+#             */
/*   Updated: 2025/12/11 12:52:02 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	debug_color(const char *name, int color)
{
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	printf("%s: %d -> (R:%d, G:%d, B:%d)\n", name, color, r, g, b);
}

void	debug_game(t_cub *game, t_texturse *txt)
{
	int	i;

	i = 0;
	printf("===== DEBUG GAME =====\n");
	printf("Map width: %d\n", game->map.width);
	printf("Map height: %d\n", game->map.height);
	debug_color("Floor", game->map.f_color);
	debug_color("Ceiling", game->map.c_color);
	printf("\nTextures:\n");
	printf("  NO: -> %s\n", txt->no);
	printf("  SO: -> %s\n", txt->so);
	printf("  WE: -> %s\n", txt->we);
	printf("  EA: -> %s\n", txt->ea);
	printf("\nMap grid:\n");
	while (i < game->map.height && game->map.grid[i])
	{
		printf("%s\n", game->map.grid[i]);
		i++;
	}
	printf("======================\n");
}

void	debug_map_grid(t_cub *game)
{
	int	i;

	i = 0;
	while (i < game->map.height && game->map.grid[i])
	{
		printf("%s", game->map.grid[i]);
		i++;
	}
}

void	debug_player(int x, int y, char dir)
{
	printf("Player position: (%d,%d) facing '%c'\n", x, y, dir);
}
