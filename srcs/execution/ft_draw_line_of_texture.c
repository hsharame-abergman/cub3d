/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line_of_texture.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:38:39 by abergman          #+#    #+#             */
/*   Updated: 2025/02/16 17:27:07 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_draw_line_of_texture(t_data *store, int x)
{
	unsigned int	bin_color;
	t_draw			*draw;
	int				y;
	int				height_tex;

	height_tex = store->north->height;
	draw = store->draw;
	ft_texture_params_init(store);
	y = store->ray->start - 1;
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
