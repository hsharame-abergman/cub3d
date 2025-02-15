/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_drawing_params.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:33:15 by abergman          #+#    #+#             */
/*   Updated: 2025/02/15 17:25:04 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_drawing_params(t_data *store, int x)
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
