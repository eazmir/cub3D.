/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <eazmir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:14:06 by eazmir            #+#    #+#             */
/*   Updated: 2025/12/10 00:27:21 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../config.h"

char	**ft_cp_map(int fd, int height)
{
	char	**dest;
	char	*line;
	char	*prev_line;
	int		i;

	dest = ft_malloc(sizeof(char *) * (height + 1), 1);
	if (!dest)
		return (NULL);
	line = get_next_line(fd);
	i = 0;
	while (i < height && line)
	{
		dest[i] = ft_strdup(line);
		line = get_next_line(fd);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

char	**ft_remove_newline_from_map(t_cub *game, char **src, int height)
{
	char	**dest;
	int		i;
	int		j;

	dest = ft_malloc(sizeof(char *) * (height + 1), 1);
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (i < height)
	{
		if (!src[i] || (src[i][0] == '\0' && ft_strlen(src[i]) == 1))
		{
			i++;
			continue ;
		}
		dest[j] = ft_strdup(src[i]);
		j++;
		i++;
	}
	dest[j] = NULL;
	game->norm.height = j;
	return (dest);
}

int	ft_get_height(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		line = get_next_line(fd);
	}
	return (i);
}
