/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:14:20 by hsharame          #+#    #+#             */
/*   Updated: 2025/02/02 20:47:26 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

bool	check_size_map(t_map *map)
{
	if (map->height <= 2)
		return (false);
	return (true);
}

bool	check_walls(t_map *map)
{
	if (!check_top_bottom_walls(map->map_grid[0])
		|| !check_top_bottom_walls(map->map_grid[map->height - 1]))
		return (false);
	if (!check_no_output(map->map_grid))
		return (false);
	return (true);
}

bool	check_other_char(char *line)
{
	int	i;
	int	end;

	i = 0;
	while (line[i] == ' ')
		i++;
	end = ft_strlen(line) - 1;
	while (line[end] == '\n' || line[end] == ' ')
		end--;
	while (i <= end)
	{
		if (line[i] != '1' && line[i] != '0'
			&& !is_player(line[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	check_player_other_char(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_grid[i])
	{
		j = 0;
		if ((i != 0 && i != map->height - 1)
			&& !check_other_char(map->map_grid[i]))
			return (false);
		while (map->map_grid[i][j])
		{
			if (is_player(map->map_grid[i][j]) == 1)
				map->player++;
			if (map->player > 1)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
