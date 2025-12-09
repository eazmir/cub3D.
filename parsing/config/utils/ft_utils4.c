/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:51:13 by eazmir            #+#    #+#             */
/*   Updated: 2025/12/09 11:52:48 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../config.h"

int ft_isspace(char c)
{
    return (
        c == ' ' ||
        c == '\t' ||
        c == '\n' ||
        c == '\v' ||
        c == '\f' ||
        c == '\r'
    );
}

int is_texture_line(char *line)
{
    if (!line) 
        return 0;
    while (*line && ft_isspace(*line)) 
        line++;
    return (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0 ||
            ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0 ||
            ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0);
}

int is_map_line(char *line)
{
    if (!line)
		return (0);
    while (*line && ft_isspace(*line)) 
        line++;
    return (*line == '1' || *line == '0' || *line == 'N' ||
            *line == 'S' || *line == 'E' || *line == 'W');
}

int check_map_position(char **lines)
{
    int map_started = 0;
    int i;

    i = 0;
    while (lines[i])
    {
        if (is_map_line(lines[i]))
            map_started = 1;
        if (map_started && is_texture_line(lines[i]))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

