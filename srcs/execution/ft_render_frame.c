/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:47:38 by abergman          #+#    #+#             */
/*   Updated: 2025/02/02 15:33:52 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	ft_render_frame(t_data *store)
{
	int		x;
	t_ray	ray;

	x = 0;
	ft_render_floor(store);
	while (x < store->win_width)
	{
		ft_ray_casting(store, &ray, x);
		ft_render_column(store, &ray, x);
		x++;
	}
	mlx_put_image_to_window(store->mlx, store->mlx_win, store->map->main->image,
		0, 0);
}
