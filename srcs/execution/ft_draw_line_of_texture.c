/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line_of_texture.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:38:39 by abergman          #+#    #+#             */
/*   Updated: 2025/02/16 20:39:23 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_draw_line(t_data *s, t_sprite *frame, int height_tex, int x)
{
	int				y;
	unsigned int	color;

	y = s->ray->start - 1;
	while (++y <= s->ray->end)
	{
		if (y < 0 || y >= HEIGHT)
			continue ;
		if (isnan(s->draw->texpos) || isinf(s->draw->texpos))
			s->draw->texpos = 0.0;
		s->draw->texy = ((int)s->draw->texpos) & (height_tex - 1);
		s->draw->texpos += s->draw->step;
		if (s->map->map_grid[s->ray->map_y][s->ray->map_x] != '1'
			|| !s->animation->active)
		{
			color = ft_get_tetxure_color(s);
		}
		else
		{
			color = *(unsigned int *)(frame->address + (s->draw->texy
						* frame->line_length + s->draw->texx
						* (frame->bits_per_pixel / 8)));
		}
		ft_mlx_pixel_put(x, y, s->main, color);
	}
}

/*
 * This function is responsible for drawing a vertical line of texture
 * on the screen at the specified x-coordinate. It uses the data stored
 * in the t_data structure to determine the texture and other parameters
 * required for drawing.
 */
void	ft_draw_line_of_texture(t_data *store, int x)
{
	int			height_tex;
	t_sprite	*frame;

	frame = NULL;
	ft_texture_params_init(store);
	if (store->map->map_grid[store->ray->map_y][store->ray->map_x] == '1'
		&& store->animation->active)
	{
		ft_update_sprite_animation(store->animation);
		frame = &store->animation->frames[store->animation->current_frame];
		height_tex = frame->height;
	}
	else
	{
		height_tex = store->north->height;
	}
	ft_draw_line(store, frame, height_tex, x);
}
