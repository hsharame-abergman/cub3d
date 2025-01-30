/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:47:38 by abergman          #+#    #+#             */
/*   Updated: 2025/01/30 16:09:21 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	ft_render_column(t_data *store, t_ray *ray, int x)
{
	
}

void	ft_raycasting(t_data *store, t_ray *ray, int x)
{
}

void	ft_render_frame(t_data *store)
{
	int		x;
	t_ray	ray;

	x = 0;
	ft_render_floor(store);
	while (x < store->win_width)
	{
		ft_raycasting(store, &ray, x);
		ft_render_column(store, &ray, x);
		x++;
	}
	mlx_put_image_to_window(store->mlx, store->mlx_win, store->map->main->image,
		0, 0);
}
