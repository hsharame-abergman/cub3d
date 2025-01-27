/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialisation_main_texture.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:30:48 by abergman          #+#    #+#             */
/*   Updated: 2025/01/27 17:35:14 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

int	ft_initialisation_main_texture(t_data *store, t_texture *main)
{
	main->image = mlx_new_image(store->mlx, store->win_width,
			store->win_height);
	if (!main->image)
		return (ft_error_handler("Main image not installed, fatal error", 1));
	main->address = mlx_get_data_addr(main->image, &main->bits_per_pixel,
			&main->line_length, &main->endian);
	if (!main->address)
		return (ft_error_handler("Main image not installed, fatal error", 1));
	return (0);
}
