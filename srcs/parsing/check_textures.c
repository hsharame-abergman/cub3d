/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:20:12 by hsharame          #+#    #+#             */
/*   Updated: 2025/02/03 12:36:42 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

bool	valide_texture(t_data *data, char *line)
{
	char	**separated;

	separated = ft_split(line, ' ');
	if (!separated || !separated[0] || !separated[1])
		return (free_tab(separated), false);
	if (!ft_strncmp(separated[0], "NO", 2) && !data->north->path)
		data->north->path = ft_strdup(separated[1]);
	else if (!ft_strncmp(separated[0], "SO", 2) && !data->south->path)
		data->south->path = ft_strdup(separated[1]);
	else if (!ft_strncmp(separated[0], "WE", 2) && !data->west->path)
		data->west->path = ft_strdup(separated[1]);
	else if (!ft_strncmp(separated[0], "EA", 2) && !data->east->path)
		data->east->path = ft_strdup(separated[1]);
	else
		return (free_tab(separated), false);
	return (free_tab(separated), true);
}

bool	find_textures(t_data *data, t_map *map)
{
	int	i;

	i = 0;
	while (map->initial_map[i])
	{
		valide_texture(data, map->initial_map[i]);
		i++;
	}
	if (!data->north->path || !data->south->path
		|| !data->west->path || !data->east->path)
		return (false);
	return (true);
}

bool	check_textures_colors(t_data *data, t_map *map)
{
	if (!find_textures(data, map))
	{
		ft_putstr_fd("Invalid textures\n", 2);
		return (false);
	}
	if (!find_colors(map))
	{
		ft_putstr_fd("Invalid colors\n", 2);
		return (false);
	}
	return (true);
}
