/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:15:27 by abergman          #+#    #+#             */
/*   Updated: 2025/02/16 20:14:24 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#define SQUARE_SIZE 3

static void	ft_draw_square(int x, int y, t_texture *t, int color)
{
	int	i;
	int	j;
	int	pixel_x;
	int	pixel_y;

	i = 0;
	while (i < SQUARE_SIZE)
	{
		j = 0;
		while (j < SQUARE_SIZE)
		{
			pixel_x = x * SQUARE_SIZE + i + 17;
			pixel_y = y * SQUARE_SIZE + j + (HEIGHT - HEIGHT / 4);
			ft_mlx_pixel_put(pixel_x, pixel_y, t, color);
			j++;
		}
		i++;
	}
}

static void	ft_draw_map_element(char element, int x, int y, t_data *store)
{
	if (element == WALL)
		ft_draw_square(x, y, store->main, store->map->c_color);
	else if (element == FLOOR)
		ft_draw_square(x, y, store->main, store->map->f_color);
}

void	ft_mini_map(t_data *store)
{
	int	i;
	int	j;

	i = -1;
	while (store->map->map_grid[++i])
	{
		j = -1;
		while (store->map->map_grid[i][++j])
			ft_draw_map_element(store->map->map_grid[i][j], j, i, store);
	}
	ft_draw_square(store->player->x, store->player->y, store->main, 0x000);
}
