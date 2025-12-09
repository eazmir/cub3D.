/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:14:07 by eazmir            #+#    #+#             */
/*   Updated: 2025/08/26 16:15:07 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "../include/parsing.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stddef.h>

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"

typedef struct s_texturse	t_texturse;
typedef struct s_cub		t_cub;

int							ft_checker2(char *line);
int							ft_check_space_on_map(char **map, int height,
								int width);
int							ft_getcolors(t_cub *game);
int							ft_check_txt_error(t_cub *game, t_texturse *txt);
int							ft_check_mltple_txtrse(char **maps, int height);
int							ft_check_walls_open(char **map, int height,
								int width);
int							ft_check_error(char **map, int height, int width);
int							ft_check_player(char **maps, int height, int width);
int							ft_check_close_walls(char **maps, int height,
								int width);
int							ft_check_characters(char **map, int height,
								int width);
int							ft_check_rectangle(char **map, int height);
int							*ft_get_position(char **map, int height, int width);
int							ft_check_txt_isvald(t_cub *game, t_texturse *txt);
int							ft_skip_space(char *s, int i);
int							ft_check(char *s);
int							ft_get_height(int fd);
int							ft_texturse_formate(char *key, int i);
int							ft_checker(char *line);
int							ft_checker2(char *line);
int							ft_force_checker(char *s);
int							ft_check_fc(char *s);
int							ft_isvalid(char *r, char *g, char *b);
int							ft_check_lines(char **p);
int							is_invalid_space(char **map_copy, int i, int j, int height);
int							ft_check_empty_values(char **rgb);
int							check_floor_color(t_cub *game);
int							check_ceiling_color(t_cub *game);
int 						is_map_line(char *line);
int							ft_checker3(char *line);
char						*clean_component(char *value, char key,
								int is_first);
char						**get_rgb_components(char **maps, char key,
								int height);
char						*trim_string(char *s);
int							check_map_position(char **lines);
char						*ft_getlines(char **maps, char key, int height);
char						**ft_cp2d(t_cub *game, char **src, int height);
char						**ft_cp_map(int fd, int height);
char						**ft_remove_newline_from_map(t_cub *game,
								char **src, int height);
void						error(char *str);
void						init_texturse(t_texturse *txt);
void						init_cub(t_cub *cub);
void						remove_space_newline(char *str);
void						ft_remove_newline(char *str);
bool						ft_check_status_file(char *file);
#endif