/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:18:13 by hsharame          #+#    #+#             */
/*   Updated: 2025/01/21 15:00:01 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

bool	check_values(char **separated)
{
	int	i;
	int	j;

	i = 0;
	while (separated[i])
	{
		if (i >= 3)
			return (false);
		j = 0;
		while (separated[i][j])
		{
			if (!ft_isdigit(separated[i][j]) && separated[i][j] != '\n')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	extract_color(t_map *map, char c, char *line)
{
	char	**separated;
	int		i;

	i = 0;
	separated = ft_split(line, ',');
	if (!separated || !separated[0] || !separated[1] || !separated[2]
		|| !check_values(separated))
		return (free_tab(separated), false);
	while (i <= 2)
	{
		map->rgb[i] = ft_atoi(separated[i]);
		if (map->rgb[i] < 0 || map->rgb[i] > 255)
			return (free_tab(separated), false);
		i++;
	}
	if (c == 'F')
		map->f_color = rgb_to_int(map->rgb[0], map->rgb[1], map->rgb[2]);
	else if (c == 'C')
		map->c_color = rgb_to_int(map->rgb[0], map->rgb[1], map->rgb[2]);
	return (free_tab(separated), true);
}

/*
	In the file we find the description of the colors for the ceiling and the floor.
	After the format transformation to int from rgb, we store the value in the
	structure.
*/
bool	valide_color(t_map *map, char *line)
{
	char	*sub_line;
	int		i;
	char	c;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	c = line[i++];
	if (c == 'F' || c == 'C')
	{
		while (ft_isspace(line[i]))
			i++;
		sub_line = ft_substr(line, i, ft_strlen(line));
		if (extract_color(map, c, sub_line))
			return (free(sub_line), true);
		free(sub_line);
	}
	return (false);
}

bool	find_colors(t_map *map)
{
	int	i;
	int	colors;

	i = 0;
	colors = 0;
	while (map->initial_map[i])
	{
		if (valide_color(map, map->initial_map[i]))
			colors++;
		i++;
	}
	if (colors != 2 || !map->f_color || !map->c_color)
		return (false);
	return (true);
}
