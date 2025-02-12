/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialisation_main_texture.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:30:48 by abergman          #+#    #+#             */
/*   Updated: 2025/02/12 17:43:01 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

int	ft_initialisation_main_texture(t_data *store)
{
	store->main = (t_texture *)malloc(sizeof(t_texture));
	if (!store->main)
		return (0);
	store->main->path = NULL;
	store->mlx = mlx_init();
	if (!store->mlx)
		return (0);
	store->mlx_win = mlx_new_window(store->mlx, WIDTH, HEIGHT, "Cub3D");
	if (!store->mlx_win)
		return (0);
	store->main->image = mlx_new_image(store->mlx, WIDTH, HEIGHT);
	if (!store->main->image)
		return (0);
	store->main->address = mlx_get_data_addr(store->main->image,
			&(store->main->bits_per_pixel), &(store->main->line_length),
			&(store->main->endian));
	if (!store->main->address)
		return (0);
	return (1);
}
