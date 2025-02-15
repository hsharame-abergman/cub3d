/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_params_init.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:39:51 by abergman          #+#    #+#             */
/*   Updated: 2025/02/15 17:25:53 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_texture_params_init(t_data *store)
{
	if (store->ray->side == 0 || store->ray->side == 1)
		store->draw->wallx = store->player->y + store->ray->walldist
			* store->ray->raydir_y;
	else
		store->draw->wallx = store->player->x + store->ray->walldist
			* store->ray->raydir_x;
	store->draw->wallx -= floor((store->draw->wallx));
	store->draw->texx = (int)(store->draw->wallx
			* (double)(store->north->width));
	if ((store->ray->side == 0 || store->ray->side == 1)
		&& store->player->dir_x >= 0)
		store->draw->texx = store->north->width - store->draw->texx - 1;
	if ((store->ray->side == 2 || store->ray->side == 3)
		&& store->player->dir_y <= 0)
		store->draw->texx = store->north->width - store->draw->texx - 1;
	store->draw->step = 1.0 * store->north->height / store->draw->lineh;
	store->draw->texpos = (store->ray->start - HEIGHT / 2 + store->draw->lineh
			/ 2) * store->draw->step;
}
