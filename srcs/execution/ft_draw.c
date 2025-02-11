/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:43:54 by abergman          #+#    #+#             */
/*   Updated: 2025/02/11 21:25:07 by abergman         ###   ########.fr       */
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

void	ft_draw_texture(t_data *store, int x)
{
	unsigned int	color;
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
		if (store->ray->side == 0)
			color = ((unsigned int *)(store->north->address))[HEIGHT_TEXTURE
				* store->draw->texy + store->draw->texx];
		else if (store->ray->side == 1)
			color = ((unsigned int *)(store->east->address))[HEIGHT_TEXTURE
				* store->draw->texy + store->draw->texx];
		else if (store->ray->side == 2)
			color = ((unsigned int *)(store->south->address))[HEIGHT_TEXTURE
				* store->draw->texy + store->draw->texx];
		else if (store->ray->side == 3)
			color = ((unsigned int *)(store->west->address))[HEIGHT_TEXTURE
				* store->draw->texy + store->draw->texx];
		ft_mlx_pixel_put(x, y, store->main, color);
	}
}

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
