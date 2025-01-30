/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:18:43 by abergman          #+#    #+#             */
/*   Updated: 2025/01/27 20:22:17 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

static	ft_mlx_pixel_put(t_texture *texture, int x, int y, int color)
{
	char	*dst;

	dst = texture->address + (y * texture->line_length + x
			* (texture->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_clear_window(t_data *store, t_texture *main)
{
	int	x;
	int	y;

	x = 0;
	while (x < store->win_width)
	{
		y = 0;
		while (y < store->win_height)
		{
			ft_mlx_pixel_put(store->map->main, x, y, 0x000000);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(store->mlx, store->mlx_win, main->image, 0, 0);
}
