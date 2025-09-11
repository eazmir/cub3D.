/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:31:23 by eazmir            #+#    #+#             */
/*   Updated: 2025/09/05 09:31:28 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../config.h"

int	is_invalid_space(char **map, size_t i, size_t j)
{
	if (map[i][j] != '0' && map[i][j] != 'N' && map[i][j] != 'E'
		&& map[i][j] != 'S' && map[i][j] != 'W')
		return (0);
	if (i == 0 || j >= ft_strlen(map[i - 1]) || map[i - 1][j] == ' ')
		return (1);
	if (!map[i + 1] || j >= ft_strlen(map[i + 1]) || map[i + 1][j] == ' ')
		return (1);
	if (j == 0 || map[i][j - 1] == ' ')
		return (1);
	if (j + 1 >= ft_strlen(map[i]) || map[i][j + 1] == ' ')
		return (1);
	return (0);
}

int	ft_is_only_digits(char *s)
{
	int		i;
	char	*str_clean;

	if (!s)
		return (0);
	str_clean = trim_string(s);
	i = 0;
	while (str_clean[i])
	{
		if (!ft_isdigit(str_clean[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_isvalid(char *r, char *g, char *b)
{
	if (!r || !g || !b)
		return (0);
	if (!ft_is_only_digits(r))
		return (0);
	if (!ft_is_only_digits(g))
		return (0);
	if (!ft_is_only_digits(b))
		return (0);
	return (1);
}

void	remove_space_newline(char *str)
{
	int	len;

	if (!str)
		return ;
	len = ft_strlen(str);
	while (len > 0)
	{
		if (str[len - 1] == ' ' || str[len - 1] == '\t' || str[len - 1] == '\n'
			|| str[len - 1] == '\r')
		{
			str[len - 1] = '\0';
			len--;
		}
		else
		{
			break ;
		}
	}
}

int	ft_check_lines(char **p)
{
	int		i;
	char	*cmp;

	i = 0;
	while (i < 4)
	{
		if (!p[i])
			return (0);
		cmp = ft_strrchr(p[i], '.');
		if (!cmp)
			return (0);
		remove_space_newline(cmp);
		if (ft_strlen(cmp) != 4)
			return (0);
		i++;
	}
	return (1);
}
