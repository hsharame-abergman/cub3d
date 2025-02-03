/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:23:11 by hsharame          #+#    #+#             */
/*   Updated: 2025/02/03 12:47:56 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

int	find_start(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (map[i][j] == '1')
			return (i);
		i++;
	}
	return (-1);
}

int	find_end(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
		i++;
	while (i-- >= 0)
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (map[i][j] == '1')
			return (i);
	}
	return (-1);
}

char	**extract_map(char **dirty, int start, int end)
	{
	char	**map;
	int		i;

	i = 0;
	if (start == -1 || end == -1 || start > end)
		return (NULL);
	map = malloc(sizeof(char *) * (end - start + 2));
	if (!map)
		return (NULL);
	while (start <= end)
	{
		map[i] = ft_strdup(dirty[start]);
		start++;
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	display_grid(char **grid)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == '1')
				ft_putchar_fd(35, 1);
			else if (grid[i][j] == '0')
				ft_putchar_fd(' ', 1);
			else
				ft_putchar_fd(grid[i][j], 1);
			j++;
		}
		i++;
	}
}

/*
    In the draft of a map, which also contains other information, such as
    the color or the path to the textures, we find the description of the
    map itself, we find the beginning and the end and we generate the clean
    copy of the map.
*/
bool	find_grid(t_map *map, char **dirty_map)
{
	int	start;
	int	end;

	start = find_start(dirty_map);
	if (start == -1)
		return (false);
	end = find_end(dirty_map);
	map->height = end - start + 1;
	map->map_grid = extract_map(dirty_map, start, end);
	if (!map->map_grid)
		return (false);
	display_grid(map->map_grid);
	return (true);
}
