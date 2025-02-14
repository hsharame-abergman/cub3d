/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digital_differential_analyzer.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:54:14 by abergman          #+#    #+#             */
/*   Updated: 2025/02/14 22:26:11 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	ft_digital_differential_analyzer(t_data *store)
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
	ft_calculate_distance_to_wall(store);
}
