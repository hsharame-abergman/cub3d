/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line_of_texture.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:38:39 by abergman          #+#    #+#             */
/*   Updated: 2025/02/15 17:24:37 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_draw_line_of_texture(t_data *store, int x)
{
	unsigned int	bin_color;
	int				y;

	ft_texture_params_init(store);
	y = store->ray->start - 1;
	while (++y <= store->ray->end)
	{
		if (y < 0 || y >= HEIGHT)
			continue ;
		if (isnan(store->draw->texpos) || isinf(store->draw->texpos))
			store->draw->texpos = 0.0;
		store->draw->texy = ((int)store->draw->texpos) & (store->north->height
				- 1);
		store->draw->texy = (int)store->draw->texpos & (store->north->height
				- 1);
		store->draw->texpos += store->draw->step;
		bin_color = ft_get_tetxure_color(store);
		ft_mlx_pixel_put(x, y, store->main, bin_color);
	}
}
