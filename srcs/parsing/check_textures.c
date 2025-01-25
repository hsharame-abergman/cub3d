/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:20:12 by hsharame          #+#    #+#             */
/*   Updated: 2025/01/25 22:47:09 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

bool	valide_texture(t_data *data, char *line)
{
	char	**separated;

	separated = ft_split(line, ' ');
	if (!separated || !separated[0] || !separated[1])
		return (free_tab(separated), false);
	if (!ft_strncmp(separated[0], "NO", 2) && !data->north)
		data->north->path = ft_strdup(separated[1]);
	else if (!ft_strncmp(separated[0], "SO", 2) && !data->south)
		data->south->path = ft_strdup(separated[1]);
	else if (!ft_strncmp(separated[0], "WE", 2) && !data->west)
		data->west->path = ft_strdup(separated[1]);
	else if (!ft_strncmp(separated[0], "EA", 2) && !data->east)
		data->east->path = ft_strdup(separated[1]);
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
		if (valide_texture(data, map->initial_map[i]))
			textures++;
		i++;
	}
	if (textures != 4 || !data->north || !data->south
		|| !data->west || !data->east)
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
