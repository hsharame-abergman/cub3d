/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:43:54 by abergman          #+#    #+#             */
/*   Updated: 2025/02/14 22:22:59 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	ft_floor_and_ceiling(t_data *store, int f_color, int c_color)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			if (y < HEIGHT / 2)
				ft_mlx_pixel_put(x, y, store->main, c_color);
			else
				ft_mlx_pixel_put(x, y, store->main, f_color);
		}
	}
}

void	ft_raycasting(t_data *store)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		ft_init_drawing_params(store, x);
		ft_calculate_start_step(store);
		ft_digital_differential_analyzer(store);
		ft_compute_wall_projection(store);
		ft_draw_line_of_texture(store, x);
	}
}

int	ft_draw(t_data *store)
{
	ft_floor_and_ceiling(store, store->map->f_color, store->map->c_color);
	ft_raycasting(store);
	mlx_put_image_to_window(store->mlx, store->mlx_win, store->main->image, 0,
		0);
	ft_mini_map(store);
	return (1);
}
