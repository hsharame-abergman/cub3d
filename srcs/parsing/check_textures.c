/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:20:12 by hsharame          #+#    #+#             */
/*   Updated: 2025/01/03 18:56:40 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

/*
	We check if the line starts with one of the sides for the textures,
	if it is the case we fill the appropriate variables.
	map->textures is an array of 4 cells, each cell corresponds to one of the
	directions. 
	For example, NORTH equals 0, so map->textures[0] will point to the image for
	the north texture.
	We also count the number of textures.
*/
bool	valide_texture(t_data *data, t_map *map, char *line)
{
	char	**separated;

	separated = ft_split(line, ' ');
	if (!separated || !separated[0] || !separated[1])
		return (free_tab(separated), false);
	if (!ft_strncmp(separated[0], "NO", 2) && !map->textures[NORTH])
		map->textures[NORTH] = mlx_xpm_file_to_image(data->mlx,
				separated[1], &map->texture_width, &map->texture_height);
	else if (!ft_strncmp(separated[0], "SO", 2) && !map->textures[SOUTH])
		map->textures[SOUTH] = mlx_xpm_file_to_image(data->mlx,
				separated[1], &map->texture_width, &map->texture_height);
	else if (!ft_strncmp(separated[0], "WE", 2) && !map->textures[WEST])
		map->textures[WEST] = mlx_xpm_file_to_image(data->mlx,
				separated[1], &map->texture_width, &map->texture_height);
	else if (!ft_strncmp(separated[0], "EA", 2) && !map->textures[EAST])
		map->textures[EAST] = mlx_xpm_file_to_image(data->mlx,
				separated[1], &map->texture_width, &map->texture_height);
	else
		return (free_tab(separated), false);
	return (free_tab(separated), true);
}

bool	find_textures(t_data *data, t_map *map)
{
	int	i;
	int	textures;

	i = 0;
	textures = 0;
	while (map->initial_map[i])
	{
		if (valide_texture(data, map, map->initial_map[i]))
			textures++;
		i++;
	}
	if (textures != 4 || !map->textures[NORTH] || !map->textures[SOUTH]
		|| !map->textures[WEST] || !map->textures[EAST])
		return (false);
	return (true);
}

bool	check_textures_colors(t_data *data, t_map *map)
{
	if (!find_textures(data, map) || !find_colors(map))
	{
		ft_putstr_fd("Invalid colors or textures\n", 2);
		return (false);
	}
	return (true);
}
