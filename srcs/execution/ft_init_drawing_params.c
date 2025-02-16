/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_drawing_params.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:33:15 by abergman          #+#    #+#             */
/*   Updated: 2025/02/16 16:34:37 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_ray_direction(t_data *store, int x)
{
	t_player	*p;

	p = store->player;
	store->ray->camera = 2 * x / (double)(WIDTH)-1;
	store->ray->raydir_x = p->dir_x + p->vector_x * store->ray->camera;
	store->ray->raydir_y = p->dir_y + p->vector_y * store->ray->camera;
}

static void	init_ray_position(t_data *store)
{
	store->ray->map_x = (int)(store->player->x);
	store->ray->map_y = (int)(store->player->y);
}

static void	init_ray_distances(t_data *store)
{
	store->ray->deltadist_x = fabs(1 / store->ray->raydir_x);
	store->ray->deltadist_y = fabs(1 / store->ray->raydir_y);
}

void	ft_init_drawing_params(t_data *store, int x)
{
	init_ray_direction(store, x);
	init_ray_position(store);
	init_ray_distances(store);
	store->ray->hit = false;
}
