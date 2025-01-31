/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_column.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:12:05 by abergman          #+#    #+#             */
/*   Updated: 2025/01/31 22:40:33 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

int	ft_calculate_texture_x(t_data *store, t_ray *ray, t_texture *texture)
{
	double	wall_x;
	int		x_texture;

	if (ray->side == 0)
		wall_x = store->player->y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = store->player->x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	x_texture = (int)(wall_x * (double)texture->width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		x_texture = texture->width - x_texture - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		x_texture = texture->width - x_texture - 1;
	return (x_texture);
}

int	ft_calculate_texture_y(int y, int line_height, t_texture *texture,
		t_data *store)
{
	int	y_texture;
	int	d;

	d = y * 256 - store->win_height * 128 + line_height * 128;
	y_texture = ((d * texture->height) / line_height) / 256;
	return (y_texture);
}

unsigned int	ft_calculate_texture_color(t_texture *texture, int x_texture,
		int y_texture)
{
	char	*pixel;
	int		color;

	pixel = texture->address + (y_texture * texture->line_length + x_texture
			* (texture->bits_per_pixel / 8));
	color = *(unsigned int *)pixel;
	return (color);
}

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
