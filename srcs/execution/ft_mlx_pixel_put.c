/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:27:51 by abergman          #+#    #+#             */
/*   Updated: 2025/02/05 01:52:10 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	ft_mlx_pixel_put(int x, int y, t_texture *main, int color_bin)
{
	int	i;

	i = (x * main->bits_per_pixel / 8) + (y * main->line_length);
	main->address[i] = (char)color_bin;
	main->address[++i] = (char)(color_bin >> 8);
	main->address[++i] = (char)(color_bin >> 16);
}
