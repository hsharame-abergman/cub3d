/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_distance_to_wall.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:55:33 by abergman          #+#    #+#             */
/*   Updated: 2025/02/15 17:23:58 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_calculate_distance_to_wall(t_data *store)
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
