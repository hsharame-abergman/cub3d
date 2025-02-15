/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute_wall_projection.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:49:34 by abergman          #+#    #+#             */
/*   Updated: 2025/02/15 17:36:05 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_compute_wall_projection(t_data *store)
{
	double	line_height;

	if (store->ray->walldist <= DEFAULT_DOUBLE)
	{
		store->ray->walldist = DEFAULT_DOUBLE;
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
