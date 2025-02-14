/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_start_step.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:57:53 by abergman          #+#    #+#             */
/*   Updated: 2025/02/14 22:25:33 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	ft_calculate_start_step(t_data *store)
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
