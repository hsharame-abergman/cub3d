/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:15:27 by abergman          #+#    #+#             */
/*   Updated: 2025/02/16 21:11:55 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_draw_square(int x, int y, t_data *s, int color)
{
	int	i;
	int	j;
	int	pixel_x;
	int	pixel_y;
	int	size;

	size = (HEIGHT / s->map->height) / 5;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			pixel_x = x * size + i + 17;
			pixel_y = y * size + j - 17;
			pixel_y += (HEIGHT - (s->map->height * size));
			ft_mlx_pixel_put(pixel_x, pixel_y, s->main, color);
			j++;
		}
		i++;
	}
}

static void	ft_draw_map_element(char element, int x, int y, t_data *store)
{
	if (element == WALL)
		ft_draw_square(x, y, store, store->map->c_color);
	else if (element == FLOOR)
		ft_draw_square(x, y, store, store->map->f_color);
}

void	ft_mini_map(t_data *store)
{
	int	y;
	int	x;

	y = -1;
	while (store->map->map_grid[++y])
	{
		x = -1;
		while (store->map->map_grid[y][++x])
			ft_draw_map_element(store->map->map_grid[y][x], x, y, store);
	}
	ft_draw_square(store->player->x, store->player->y, store, 0x000);
}
