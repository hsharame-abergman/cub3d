/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:18:43 by abergman          #+#    #+#             */
/*   Updated: 2025/01/30 16:08:58 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	ft_mlx_pixel_put(int x, int y, t_texture *texture, int color)
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
			ft_mlx_pixel_put(x, y, store->map->main, 0x000000);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(store->mlx, store->mlx_win, main->image, 0, 0);
}
