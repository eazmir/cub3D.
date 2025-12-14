/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:43:09 by eazmir            #+#    #+#             */
/*   Updated: 2025/12/14 13:44:32 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../config.h"

int	get_map_width(char **map)
{
	int	max_width;
	int	current_width;
	int	i;

	max_width = 0;
	i = 0;
	while (map[i])
	{
		current_width = ft_strlen(map[i]);
		if (current_width > max_width)
			max_width = current_width;
		i++;
	}
	return (max_width);
}
