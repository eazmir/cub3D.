/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:51:01 by eazmir            #+#    #+#             */
/*   Updated: 2025/08/25 17:53:02 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int	ft_check_border_row(char *row)
{
	int	j;
	int	len;

	j = 0;
	len = ft_strlen(row);
	if (len > 0 && row[len - 1] == '\n')
		len--;
	while (j < len)
	{
		if (row[j] != '1' && row[j] != ' ')
			return (0);
		j++;
	}
	return (1);
}

int	ft_check_middle_row(char *row)
{
	int	j;
	int	len;

	len = ft_strlen(row);
	if (len > 0 && row[len - 1] == '\n')
		len--;
	j = 0;
	while (j < len && row[j] == ' ')
		j++;
	if (j < len && row[j] != '1')
		return (0);
	j = len - 1;
	while (j >= 0 && row[j] == ' ')
		j--;
	if (row[j] != '1')
		return (0);
	return (1);
}

int	ft_check_close_walls(char **maps, int height, int width)
{
	int	i;

	(void)width;
	i = 0;
	while (i < height)
	{
		if (i == 0 || i == height - 1)
		{
			if (!ft_check_border_row(maps[i]))
				return (0);
		}
		else
		{
			if (!ft_check_middle_row(maps[i]))
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_characters(char **map, int height, int width)
{
	int	i;
	int	j;
	int	l;

	(void)width;
	i = 0;
	while (i < height)
	{
		j = 0;
		l = ft_strlen(map[i]);
		while (j < l)
		{
			if (l == 1)
				return (0);
			if (!ft_strchr("10NSEW ", map[i][j]))
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_space_on_map(char **map, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		width = ft_strlen(map[i]);
		j = 0;
		while (j < width && map[i][j])
		{
			if (is_invalid_space(map, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
