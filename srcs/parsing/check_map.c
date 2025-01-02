/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:40:58 by hsharame          #+#    #+#             */
/*   Updated: 2025/01/02 18:20:36 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	fill_copy_lines(t_map *map)
{
	int		i;
	char	*line;
	int 	fd;

	i = 0;
	fd = open(map->filename, O_RDONLY);
	if (fd < 0)
		return ;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		map->initial_map[i] = ft_strdup(line);
		i++;
		free(line);
	}
	map->initial_map[i] = NULL;
	close(fd);
}

bool    extract_info(t_map *map)
{
    char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(map->filename, O_RDONLY);
	if (fd < 0)
		return (false);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\0')
			break;
		i++;
		free(line);
	}
	close(fd);
	map->initial_map = malloc(sizeof(char *) * (i + 1));
	if (!map->initial_map)
		return (false);
	fill_copy_lines(map);
	return (true);
}

bool    map_is_valid(t_map *map)
{
    if (!extract_info(map))
        return (false);
    if (!check_map_texture_colors(map))
        return (false);
    /*if (!check_map(map))
        return (false);
    if (!check_map_player_positon(map))
        return (false);*/
	else
		return (true);
}
