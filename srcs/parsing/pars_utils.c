/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:22:54 by hsharame          #+#    #+#             */
/*   Updated: 2025/01/03 18:59:27 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

/*
	The mlx_pixel_put function that we will probably use after in order to put
	the floor and ceiling color uses int as color, hence the need to transform
	the RGB format into int via the bite operation and to keep it under int in
	the structure.
*/
int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	affiche_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->map_grid)
	{
		while (map->map_grid[i])
		{
			printf("%s", map->map_grid[i]);
			i++;
		}
	}
	i = 0;
	if (map->initial_map)
	{
		while (map->initial_map[i])
		{
			printf("%s", map->initial_map[i]);
			i++;
		}
	}
	printf ("%#x\n", map->f_color);
	printf ("%#x\n", map->c_color);
}
