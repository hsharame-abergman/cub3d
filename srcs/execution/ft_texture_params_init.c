/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_params_init.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:39:51 by abergman          #+#    #+#             */
/*   Updated: 2025/02/16 17:01:17 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	calculate_wallx(t_data *store)
{
	t_ray	*ray;

	ray = store->ray;
	if (store->ray->side == NORTH || store->ray->side == EAST)
		store->draw->wallx = store->player->y + ray->walldist * ray->raydir_y;
	else
		store->draw->wallx = store->player->x + ray->walldist * ray->raydir_x;
	store->draw->wallx -= floor((store->draw->wallx));
}

static void	calculate_texx(t_data *store)
{
	int	side;
	int	width;

	width = store->north->width;
	side = store->ray->side;
	store->draw->texx = (int)(store->draw->wallx * (double)(width));
	if ((side == NORTH || side == EAST) && store->player->dir_x >= 0)
		store->draw->texx = width - store->draw->texx - 1;
	if ((side == SOUTH || side == WEST) && store->player->dir_y <= 0)
		store->draw->texx = width - store->draw->texx - 1;
}

static void	calculate_step_and_texpos(t_data *store)
{
	t_draw	*draw;
	int		start;
	int		height;

	height = store->north->height;
	start = store->ray->start;
	draw = store->draw;
	draw->step = 1.0 * height / draw->lineh;
	draw->texpos = (start - HEIGHT / 2 + draw->lineh / 2) * draw->step;
	store->draw = draw;
}

void	ft_texture_params_init(t_data *store)
{
	calculate_wallx(store);
	calculate_texx(store);
	calculate_step_and_texpos(store);
}
