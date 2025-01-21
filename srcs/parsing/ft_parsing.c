/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:29:48 by hsharame          #+#    #+#             */
/*   Updated: 2025/01/21 16:50:39 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

bool	check_grid_map(t_map *map)
{
	if (!check_size_map(map) || !check_walls(map)
		|| !check_player_other_char(map))
	{
		return (false);
	}
	return (true);
}

bool	parsing(t_data *data)
{
	if (!map_is_valid(data, data->map))
	{
		free_exit(data, "The map is not valid");
		return (false);
	}
	return (true);
}
