/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_distance_to_wall.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:55:33 by abergman          #+#    #+#             */
/*   Updated: 2025/02/16 16:54:17 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static double	ft_calculate_distance(t_ray *ray, t_player *p)
{
	double	dist;

	if (ray->side == NORTH || ray->side == EAST)
		dist = (ray->map_x - p->x + (1 - ray->step_x) / 2) / ray->raydir_x;
	else
		dist = (ray->map_y - p->y + (1 - ray->step_y) / 2) / ray->raydir_y;
	return (fabs(dist));
}

void	ft_calculate_distance_to_wall(t_data *store)
{
	store->ray->walldist = ft_calculate_distance(store->ray, store->player);
	if (store->ray->walldist < DEFAULT_DOUBLE)
		store->ray->walldist = DEFAULT_DOUBLE;
}
