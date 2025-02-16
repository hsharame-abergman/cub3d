/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line_of_texture.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:38:39 by abergman          #+#    #+#             */
/*   Updated: 2025/02/16 20:39:23 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
 * This function is responsible for drawing a vertical line of texture
 * on the screen at the specified x-coordinate. It uses the data stored
 * in the t_data structure to determine the texture and other parameters
 * required for drawing.
 */
void	ft_draw_line_of_texture(t_data *store, int x)
{
	int				y;
	t_draw			*draw;
	unsigned int	bin_color;
	int				height_tex;

	draw = store->draw;
	y = store->ray->start - 1;
	ft_texture_params_init(store);
	height_tex = store->north->height;
	while (++y <= store->ray->end)
	{
		if (y < 0 || y >= HEIGHT)
			continue ;
		if (isnan(draw->texpos) || isinf(draw->texpos))
			draw->texpos = 0.0;
		draw->texy = ((int)draw->texpos) & (height_tex - 1);
		draw->texpos += draw->step;
		bin_color = ft_get_tetxure_color(store);
		ft_mlx_pixel_put(x, y, store->main, bin_color);
	}
	store->draw = draw;
}
