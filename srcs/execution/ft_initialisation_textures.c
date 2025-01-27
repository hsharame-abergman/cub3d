/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialisation_textures.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:34:04 by abergman          #+#    #+#             */
/*   Updated: 2025/01/27 17:34:55 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

static int	ft_initialisation_north_texture(t_data *store, int h, int w)
{
	store->north->image = mlx_xpm_file_to_image(store->mlx, store->north->path,
			&w, &h);
	if (!store->north->image)
		return (1);
	store->north->address = mlx_get_data_addr(store->north->image,
			&store->north->bits_per_pixel, &store->north->line_length,
			&store->north->endian);
	store->north->width = w;
	store->north->height = h;
	return (0);
}

static int	ft_initialisation_east_texture(t_data *store, int h, int w)
{
	store->east->image = mlx_xpm_file_to_image(store->mlx, store->east->path,
			&w, &h);
	if (!store->east->image)
		return (1);
	store->east->address = mlx_get_data_addr(store->east->image,
			&store->east->bits_per_pixel, &store->east->line_length,
			&store->east->endian);
	store->east->width = w;
	store->east->height = h;
	return (0);
}

static int	ft_initialisation_south_texture(t_data *store, int h, int w)
{
	store->south->image = mlx_xpm_file_to_image(store->mlx, store->south->path,
			&w, &h);
	if (!store->south->image)
		return (1);
	store->south->address = mlx_get_data_addr(store->south->image,
			&store->south->bits_per_pixel, &store->south->line_length,
			&store->south->endian);
	store->south->width = w;
	store->south->height = h;
	return (0);
}

static int	ft_initialisation_west_texture(t_data *store, int h, int w)
{
	store->west->image = mlx_xpm_file_to_image(store->mlx, store->west->path,
			&w, &h);
	if (!store->west->image)
		return (0);
	store->west->address = mlx_get_data_addr(store->west->image,
			&store->west->bits_per_pixel, &store->west->line_length,
			&store->west->endian);
	store->west->width = w;
	store->west->height = h;
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
	return (0);
}
