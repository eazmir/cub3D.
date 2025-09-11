/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:14:17 by eazmir            #+#    #+#             */
/*   Updated: 2025/09/05 09:14:20 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../config.h"

int	ft_texturse_formate(char *key, int i)
{
	if (!key || !key[i] || !key[i + 1])
		return (0);
	if (key[i] == 'N' && key[i + 1] == 'O')
		return (1);
	else if (key[i] == 'S' && key[i + 1] == 'O')
		return (2);
	else if (key[i] == 'W' && key[i + 1] == 'E')
		return (3);
	else if (key[i] == 'E' && key[i + 1] == 'A')
		return (4);
	return (0);
}

int	ft_checker(char *line)
{
	int	i;

	i = 0;
	i = ft_skip_space(line, i);
	if (line[i] == 'N' && line[i + 1] == 'O')
		return (1);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		return (2);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		return (3);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		return (4);
	return (0);
}

int	ft_checker3(char *line)
{
	int	i;

	i = 0;
	i = ft_skip_space(line, 0);
	if (line[i] == 'N' && line[i + 1] == 'O')
		return (1);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		return (2);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		return (3);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		return (4);
	else if (line[i] == 'F')
		return (5);
	else if (line[i] == 'C')
		return (6);
	return (0);
}

int	ft_checker2(char *line)
{
	int	i;

	i = 0;
	i = ft_skip_space(line, 0);
	if (line[i] == 'N' && line[i + 1] == 'O')
		return (1);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		return (2);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		return (3);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		return (4);
	return (0);
}

int	ft_force_checker(char *s)
{
	if (ft_strncmp(s, "NO", 2) == 0 || ft_strncmp(s, "SO", 2) == 0
		|| ft_strncmp(s, "WE", 2) == 0 || ft_strncmp(s, "EA", 2) == 0)
	{
		if (s[2] == ' ' || s[2] == '\t' || s[2] == '\0')
			return (1);
		else
			return (0);
	}
	return (0);
}
