/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digital_differential_analyzer.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:54:14 by abergman          #+#    #+#             */
/*   Updated: 2025/02/16 18:00:20 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Refactoring sides, for use e_num fron Hannah's header file:
North 0 -> 0
East 1 -> 3
South 2 -> 1
West 3 -> 2
 */

#include "cub3D.h"

void	ft_digital_differential_analyzer(t_data *store)
{
	while (!store->ray->hit)
	{
		if (store->ray->sidedist_x < store->ray->sidedist_y)
		{
			store->ray->sidedist_x += store->ray->deltadist_x;
			store->ray->map_x += store->ray->step_x;
			if (store->ray->step_x == -1)
				store->ray->side = WEST;
			else if (store->ray->step_x == 1)
				store->ray->side = EAST;
		}
		else
		{
			store->ray->sidedist_y += store->ray->deltadist_y;
			store->ray->map_y += store->ray->step_y;
			if (store->ray->step_y == -1)
				store->ray->side = NORTH;
			else if (store->ray->step_y == 1)
				store->ray->side = SOUTH;
		}
		if (store->map->map_grid[store->ray->map_y][store->ray->map_x] == WALL)
			store->ray->hit = true;
	}
	ft_calculate_distance_to_wall(store);
}
