/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:03:34 by eazmir            #+#    #+#             */
/*   Updated: 2025/08/25 11:13:54 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "../include/parsing.h"

typedef struct s_cub		t_cub;
typedef struct s_texturse	t_texturse;

void						debug_game(t_cub *game, t_texturse *txt);
void						debug_color(const char *name, int color);
void						debug_map_grid(t_cub *game);
void						debug_player(int x, int y, char dir);
#endif
