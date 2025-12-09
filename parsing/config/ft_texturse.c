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

int is_grid(char *s)
{
	while (*s == ' ' || *s == '\t')
		s++;

	return (*s == '1' || *s == '0');
}
static int is_empty(char *s)
{
    int i = 0;
    while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
        i++;

    return (s[i] == '\0');
}

char **get_texturse(char **line,int height)
{
	int i = 0;
	int j = 0;
	char **txt;

	txt = ft_malloc(sizeof(char *) * 5,1);
	if (!txt)
		return (NULL);
	while (i < height)
	{
		if (ft_checker(line[i]))
			txt[j++] = line[i];
		else if (is_empty(line[i]))
			;
		else if (is_grid(line[i]))
			;
		i++;
	}
	txt[j] = NULL;
	return (txt);
}
char	*ft_parse_txtrse(char *path, t_texturse *txt)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	i = ft_skip_space(path, 0);
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
	if (!maps[0] || !maps)
		return (0);
	ft_memset(c, 0, sizeof(c));
	if (!force_checker(maps, height))
		return (-1);
	i = 0;
	while (i < height)
	{
			id = ft_checker2(maps[i]);
			if (id > 0)
			{
				c[id]++;
				if (c[id] > 1)
					return (0);
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
	
	char **txt1 = get_texturse(game->norm.cp_map,game->norm.height);
	// if (!txt1)
	// 	return (0);
	if (ft_check_mltple_txtrse(txt1,4) == -1)
		return (-1);
	if (!ft_check_mltple_txtrse(txt1,4))
		return (0);
	p = ft_parse_txt_from_map(txt, txt1, 4);
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
