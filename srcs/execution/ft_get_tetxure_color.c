/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetxure_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:38:15 by abergman          #+#    #+#             */
/*   Updated: 2025/02/15 17:24:59 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

unsigned int	ft_get_tetxure_color(t_data *store)
{
	unsigned int	bin_color;

	bin_color = 0;
	if (store->ray->side == 0)
		bin_color = ((unsigned int *)(store->north->address))
		[store->north->height * store->draw->texy + store->draw->texx];
	else if (store->ray->side == 1)
		bin_color = ((unsigned int *)(store->east->address))[store->east->height
			* store->draw->texy + store->draw->texx];
	else if (store->ray->side == 2)
		bin_color = ((unsigned int *)(store->south->address))
		[store->south->height * store->draw->texy + store->draw->texx];
	else if (store->ray->side == 3)
		bin_color = ((unsigned int *)(store->west->address))[store->west->height
			* store->draw->texy + store->draw->texx];
	return (bin_color);
}
