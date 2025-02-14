/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:43:54 by abergman          #+#    #+#             */
/*   Updated: 2025/02/14 20:58:12 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

/* 	// Сначала вызывается функция `ft_init_drawing`,
		которая инициализирует параметры,
		необходимые для трассировки луча для текущей координаты `x`.

	// Затем вызывается функция `ft_calculate_step`,
		которая рассчитывает шаги для перемещения луча по сетке карты.

	// После этого вызывается функция `ft_dda`,
		которая реализует алгоритм DDA для трассировки луча.

	// После завершения алгоритма DDA вызывается функция `ft_calculate_stripe`,
		которая рассчитывает параметры для отрисовки столбца на экране.

	// Наконец, вызывается функция `ft_draw_texture`,
		которая отрисовывает столбец на экране.
 */

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
		ft_init_drawing(store, x);
		ft_calculate_step(store);
		ft_dda(store);
		ft_calculate_stripe(store);
		ft_draw_texture(store, x);
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
