/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:20:12 by hsharame          #+#    #+#             */
/*   Updated: 2025/01/02 18:27:12 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

int rgb_to_int(int r, int g, int b)
{
    return ((r << 16) | (g << 8) | b);
}

bool    find_textures(t_map *map)
{
    int i;
    int textures;

    i = 0;
    textures = 0;
    while (map->initial_map[i])
    {
        if (valide_texture(map, map->initial_map[i]))
            textures++;
        else
            return (false);
        i++;
    }
    if (textures != 4)
        return (false);
    return (true);
}

bool check_textures_colors(t_map *map)
{
	if (!find_textures(map) || !find_colors(map))
	{
		ft_putstr_fd("Invalid colors or textures\n", 2);
		return (false);
	}
	return (true);
}
