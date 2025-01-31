/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_column.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:12:05 by abergman          #+#    #+#             */
/*   Updated: 2025/01/31 19:03:48 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

int		ft_calculate_texture_x(t_data *store, t_ray *ray, t_texture *texture);
int		ft_calculate_texture_y(int y, int line_height, t_texture *texture,
			t_data *store);
unsigned int		ft_calculate_texture_color(t_texture *texture, int x_texture,
			int y_texture);

void	ft_render_column(t_data *store, t_ray *ray, int x)
{
	t_texture		*texture;
	int				x_texture;
	int				y_texture;
	int				y;
	unsigned int	color;

	texture = ft_select_texture(store, ray);
	x_texture = ft_calculate_texture_x(store, ray, texture);
	y = ray->draw_start;
	while (x < ray->draw_start)
	{
		y_texture = ft_calculate_texture_y(y, ray->line_height, texture, store);
		color = ft_calculate_texture_color(texture, x_texture, y_texture);
		ft_mlx_pixel_put(x, y, texture, color);
		y++;
	}
}
