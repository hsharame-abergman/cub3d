/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:22:54 by hsharame          #+#    #+#             */
/*   Updated: 2025/01/22 16:29:53 by hsharame         ###   ########.fr       */
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

int	is_player(int c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

bool	check_top_bottom_walls(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != ' ' && str[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

bool	space_adjacent(char **map, int i, int j)
{
	if (map[i - 1][j] == ' ' || map[i + 1][j] == ' '
		|| map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
		return (true);
	return (false);
}

bool	check_no_output(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || is_player(map[i][j]) == 1)
			{
				if (j == 0)
					return (false);
				if (space_adjacent(map, i, j))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
