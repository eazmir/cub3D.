/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texturse.config.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:44:23 by eazmir            #+#    #+#             */
/*   Updated: 2025/08/25 15:44:28 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

char	*ft_parse_txtrse(char *path, t_texturse *txt)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	i = ft_skip_space(path, i);
	if (ft_texturse_formate(path, i))
	{
		i += 2;
		i = ft_skip_space(path, i);
		j = ft_skip_space(path, j);
		if (ft_texturse_formate(path, j) == 1)
			return (txt->no = ft_strdup(path) + i);
		else if (ft_texturse_formate(path, j) == 2)
			return (txt->so = ft_strdup(path) + i);
		else if (ft_texturse_formate(path, j) == 3)
			return (txt->we = ft_strdup(path) + i);
		else if (ft_texturse_formate(path, j) == 4)
			return (txt->ea = ft_strdup(path) + i);
		else
			return (NULL);
	}
	return (NULL);
}

char	**ft_parse_txt_from_map(t_texturse *txt, char **map, int height)
{
	int		i;
	int		j;
	char	**p;
	char	*t;

	p = ft_malloc(sizeof(char *) * 5, 1);
	if (!p)
		return (NULL);
	i = 0;
	j = 0;
	while (i < height)
	{
		if (ft_checker(map[i]))
		{
			t = ft_parse_txtrse(map[i], txt);
			if (t)
				p[j++] = t;
		}
		i++;
	}
	p[j] = NULL;
	return (p);
}

int	force_checker(char **s, int height)
{
	int		i;
	char	*p;
	int		c;
	int		j;

	i = 0;
	c = 0;
	while (i < height && (s[i][0] == '\n'))
		i++;
	while (i < height && c < 4)
	{
		j = ft_skip_space(s[i], 0);
		p = ft_substr(s[i] + j, 0, 3);
		if (ft_strncmp(p, "F ", 2) == 0 || ft_strncmp(p, "C ", 2) == 0)
			i++;
		else if (!ft_force_checker(p))
		{
			return (0);
		}
		c++;
		i++;
	}
	return (1);
}

int	ft_check_mltple_txtrse(char **maps, int height)
{
	int	i;
	int	id;
	int	c[5];

	ft_memset(c, 0, sizeof(c));
	if (!force_checker(maps, height))
		return (-1);
	i = 0;
	while (i < height)
	{
		if (maps[i][0] != 'F' && maps[i][0] != 'C')
		{
			id = ft_checker2(maps[i]);
			if (id > 0)
			{
				c[id]++;
				if (c[id] > 1)
					return (0);
			}
		}
		i++;
	}
	return (1);
}

int	ft_check_txt_isvald(t_cub *game, t_texturse *txt)
{
	int		i;
	char	**p;
	char	*cmp;

	if (ft_check_mltple_txtrse(game->norm.cp_map, game->norm.height) == -1)
		return (-1);
	if (!ft_check_mltple_txtrse(game->norm.cp_map, game->norm.height))
		return (0);
	p = ft_parse_txt_from_map(txt, game->norm.cp_map, game->norm.height);
	i = 0;
	while (i < 4)
	{
		if (!p[i])
			return (0);
		cmp = ft_strrchr(p[i], '.');
		if (!cmp)
			return (0);
		remove_space_newline(cmp);
		if (ft_strlen(cmp) != 4 || ft_strncmp(cmp, ".xpm", 4) != 0)
			return (-2);
		i++;
	}
	if (!ft_check_lines(p))
		return (-2);
	return (1);
}
