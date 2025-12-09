/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 00:28:14 by eazmir            #+#    #+#             */
/*   Updated: 2025/09/07 00:29:24 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../config.h"

int	ft_count_color(char **rgb)
{
	int	c;

	if (!rgb)
		return (0);
	c = 0;
	while (rgb[c])
		c++;
	return (c);
}

int	ft_check_empty_values(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
	{
		if (rgb[i][0] == '\0')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim_color(char *str)
{
	char	*start;
	char	*end;
	char	*res;
	int		len;
	int		i;

	start = str;     
	while (*start == ' ' || *start == '\t')
		start++;
	end = start + ft_strlen(start) - 1;
	while (end > start && (*end == ' ' || *end == '\t'))
		end--;
	len = end - start + 1;
	res = ft_malloc(len + 1, 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = start[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**get_rgb_components(char **maps, char key, int height)
{
	char	*line;
	char	**rgb;

	line = ft_getlines(maps, key, height);
	if (!line)
		return (NULL);
	rgb = ft_split(line, ',');
	if (ft_count_color(rgb) != 3)
		return (NULL);
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
		return (NULL);
	return (rgb);
}

char	*clean_component(char *value, char key, int is_first)
{
	char	*trimmed;
	int		i;

	i = ft_skip_space(value, 0);
	if (is_first && value[i] == key)
		i++;
	trimmed = ft_strtrim_color(value + i);
	if (!trimmed || trimmed[0] == '\n' || trimmed[0] == '\0')
		return (NULL);
	return (trimmed);
}
