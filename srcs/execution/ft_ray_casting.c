/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:33:15 by abergman          #+#    #+#             */
/*   Updated: 2025/02/12 14:37:22 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	ft_init_drawing(t_data *store, int x)
{
	store->ray->camera = 2 * x / (double)(WIDTH)-1;
	store->ray->raydir_x = store->player->dir_x + store->player->vector_x
		* store->ray->camera;
	store->ray->raydir_y = store->player->dir_y + store->player->vector_y
		* store->ray->camera;
	store->ray->map_x = (int)(store->player->x);
	store->ray->map_y = (int)(store->player->y);
	store->ray->deltadist_x = fabs(1 / store->ray->raydir_x);
	store->ray->deltadist_y = fabs(1 / store->ray->raydir_y);
	store->ray->hit = 0;
}

void	ft_calculate_step(t_data *store)
{
	if (store->ray->raydir_x < 0)
	{
		store->ray->step_x = -1;
		store->ray->sidedist_x = (store->player->x - store->ray->map_x)
			* store->ray->deltadist_x;
	}
	else
	{
		store->ray->step_x = 1;
		store->ray->sidedist_x = (store->ray->map_x + 1.0 - store->player->x)
			* store->ray->deltadist_x;
	}
	if (store->ray->raydir_y < 0)
	{
		store->ray->step_y = -1;
		store->ray->sidedist_y = (store->player->y - store->ray->map_y)
			* store->ray->deltadist_y;
	}
	else
	{
		store->ray->step_y = 1;
		store->ray->sidedist_y = (store->ray->map_y + 1.0 - store->player->y)
			* store->ray->deltadist_y;
	}
}

void	ft_calculate_distance(t_data *store)
{
	double	dist;

	if (store->ray->raydir_x == 0.0f)
		store->ray->raydir_x = 0.0001f;
	if (store->ray->raydir_y == 0.0f)
		store->ray->raydir_y = 0.0001f;
	if (store->ray->side == 0 || store->ray->side == 1)
	{
		dist = (store->ray->map_x - store->player->x + (1 - store->ray->step_x)
				/ 2) / store->ray->raydir_x;
		store->ray->walldist = fabs(dist);
	}
	else
	{
		dist = (store->ray->map_y - store->player->y + (1 - store->ray->step_y)
				/ 2) / store->ray->raydir_y;
		store->ray->walldist = fabs(dist);
	}
	if (store->ray->walldist < 0.0001f)
		store->ray->walldist = 0.0001f;
}

void	ft_dda(t_data *store)
{
	while (store->ray->hit == 0)
	{
		if (store->ray->sidedist_x < store->ray->sidedist_y)
		{
			store->ray->sidedist_x += store->ray->deltadist_x;
			store->ray->map_x += store->ray->step_x;
			if (store->ray->step_x == -1)
				store->ray->side = 0;
			else if (store->ray->step_x == 1)
				store->ray->side = 1;
		}
		else
		{
			store->ray->sidedist_y += store->ray->deltadist_y;
			store->ray->map_y += store->ray->step_y;
			if (store->ray->step_y == -1)
				store->ray->side = 2;
			else if (store->ray->step_y == 1)
				store->ray->side = 3;
		}
		if (store->map->map_grid[store->ray->map_y][store->ray->map_x] == '1')
			store->ray->hit = 1;
	}
	ft_calculate_distance(store);
}

void	ft_calculate_stripe(t_data *store)
{
	double	line_height;

	if (store->ray->walldist <= 0.0001f)
	{
		store->ray->walldist = 0.0001f;
	}
	line_height = (double)HEIGHT / store->ray->walldist;
	if (isinf(line_height) || line_height > INT_MAX)
	{
		store->draw->lineh = HEIGHT;
	}
	else
	{
		store->draw->lineh = (int)line_height;
		if (store->draw->lineh > HEIGHT)
			store->draw->lineh = HEIGHT;
	}
	store->ray->start = (HEIGHT / 2) - (store->draw->lineh / 2);
	if (store->ray->start < 0)
		store->ray->start = 0;
	store->ray->end = (HEIGHT / 2) + (store->draw->lineh / 2);
	if (store->ray->end >= HEIGHT)
		store->ray->end = HEIGHT - 1;
}
