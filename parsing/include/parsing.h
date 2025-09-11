/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:07:48 by eazmir            #+#    #+#             */
/*   Updated: 2025/09/07 17:51:57 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include "../config/config.h"
# include "../libft/libft.h"

typedef struct s_texturse
{
	int height;
	int width;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char    *img_no;
	char    *img_so;
	char    *img_we;
	char    *img_ea;
}			t_texturse;

typedef struct s_norm
{
	char	**cp_map;
	int		height;
}			t_norm;

typedef struct s_map
{
	char **grid;  // the map grid: a 2D array of chars ('1',0)
	int c_color;  // ceiling color (stored as an int, like 0xRRGGBB)
	int f_color;  // floor color (also as 0xRRGGBB)
	int width;    // number of columns in the map
	int height;   // number of rows in the map
	int player_x; // starting X position of the player
	int player_y; // starting Y position of the player
}			t_map;

typedef struct s_cub
{
	void *mlx;
	void *win;
	char *file;  // the .cub file name (path to configuration file)
	t_norm norm; // not necessary.
	t_map map;   // Usage (t_cub *game ,game->map.grid || game.map.color ...)
	t_texturse txt;
}			t_cub;

int			init_game(t_cub **game, t_texturse **txt, char *file);
#endif
