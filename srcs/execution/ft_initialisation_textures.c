/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialisation_textures.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:34:04 by abergman          #+#    #+#             */
/*   Updated: 2025/01/25 19:24:45 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"
#include "../../header/execution.h"

static int	ft_initialistation_north_texture(t_data *store, int h, int w)
{
	store->north->image = mlx_xpm_file_to_image(store->mlx, store->north->path,
			&w, &h);
	if (!store->north->image)
		retirn(1);
	store->north->address = mlx_get_data_addr(store->north->image,
			&store->north->bits_per_pixel, &store->north->line_lenght,
			&store->north->endian);
	store->north->width = w;
	store->north->height = h;
	return (0);
}

int	ft_initialisation_textures(t_data *store)
{
	int	w;
	int	h;

	w = WIDTH_TEXTURE;
	h = HEIGHT_TEXTURE;
	if (store->north)
		if (ft_initialisation_north_texture(store, h, w))
			return (ft_error_handler("north texture can't loaded", 1), 1);
	if (store->east)
		if (ft_initialisation_east_texture(store, h, w))
			return (ft_error_handler("east texture can't loaded", 1), 1);
	if (store->south)
		if (ft_initialisation_south_texture(store, h, w))
			return (ft_error_handler("south texture can't loaded", 1), 1);
	if (store->west)
		if (ft_initialisation_west_texture(store, h, w))
			return (ft_error_handler("west texture can't loaded", 1), 1);
}
