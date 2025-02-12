/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:38:39 by abergman          #+#    #+#             */
/*   Updated: 2025/02/12 14:53:42 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	ft_tex_init(t_data *store)
{
	if (store->ray->side == 0 || store->ray->side == 1)
		store->draw->wallx = store->player->y + store->ray->walldist
			* store->ray->raydir_y;
	else
		store->draw->wallx = store->player->x + store->ray->walldist
			* store->ray->raydir_x;
	store->draw->wallx -= floor((store->draw->wallx));
	store->draw->texx = (int)(store->draw->wallx * (double)(WIDTH_TEXTURE));
	if ((store->ray->side == 0 || store->ray->side == 1)
		&& store->player->dir_x >= 0)
		store->draw->texx = WIDTH_TEXTURE - store->draw->texx - 1;
	if ((store->ray->side == 2 || store->ray->side == 3)
		&& store->player->dir_y <= 0)
		store->draw->texx = WIDTH_TEXTURE - store->draw->texx - 1;
	store->draw->step = 1.0 * HEIGHT_TEXTURE / store->draw->lineh;
	store->draw->texpos = (store->ray->start - HEIGHT / 2 + store->draw->lineh
			/ 2) * store->draw->step;
}

static unsigned int	ft_draw_sides(t_data *store)
{
	unsigned int	bin_color;

	bin_color = 0;
	if (store->ray->side == 0)
		bin_color = ((unsigned int *)(store->north->address))[HEIGHT_TEXTURE
			* store->draw->texy + store->draw->texx];
	else if (store->ray->side == 1)
		bin_color = ((unsigned int *)(store->east->address))[HEIGHT_TEXTURE
			* store->draw->texy + store->draw->texx];
	else if (store->ray->side == 2)
		bin_color = ((unsigned int *)(store->south->address))[HEIGHT_TEXTURE
			* store->draw->texy + store->draw->texx];
	else if (store->ray->side == 3)
		bin_color = ((unsigned int *)(store->west->address))[HEIGHT_TEXTURE
			* store->draw->texy + store->draw->texx];
	return (bin_color);
}

void	ft_draw_texture(t_data *store, int x)
{
	unsigned int	bin_color;
	int				y;

	ft_tex_init(store);
	y = store->ray->start - 1;
	while (++y <= store->ray->end)
	{
		if (y < 0 || y >= HEIGHT)
			continue ;
		if (isnan(store->draw->texpos) || isinf(store->draw->texpos))
			store->draw->texpos = 0.0;
		store->draw->texy = ((int)store->draw->texpos) & (HEIGHT_TEXTURE - 1);
		store->draw->texy = (int)store->draw->texpos & (HEIGHT_TEXTURE - 1);
		store->draw->texpos += store->draw->step;
		bin_color = ft_draw_sides(store);
		ft_mlx_pixel_put(x, y, store->main, bin_color);
	}
}
