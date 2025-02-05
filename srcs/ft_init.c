/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:20:44 by hsharame          #+#    #+#             */
/*   Updated: 2025/02/05 02:09:21 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

t_map	*init_map(char *filename)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->filename = filename;
	map->fd = 0;
	map->height = 0;
	map->length = 0;
	map->c_color = 0;
	map->f_color = 0;
	map->initial_map = NULL;
	map->map_grid = NULL;
	map->rgb[0] = 0;
	map->rgb[1] = 0;
	map->rgb[2] = 0;
	return (map);
}

t_player	*init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->x = 0;
	player->y = 0;
	player->dir_x = 0;
	player->dir_y = 0;
	player->vector_x = 0;
	player->vector_y = 0;
	return (player);
}

t_ray	*init_ray(void)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->raydir_x = 0;
	ray->raydir_y = 0;
	return (ray);
}

bool	init_data(t_data *data, char *file)
{
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->filename = file;
	data->map = init_map(data->filename);
	if (!data->map)
		return (false);
	data->ray = init_ray();
	data->east = ft_init_texture();
	data->north = ft_init_texture();
	data->west = ft_init_texture();
	data->south = ft_init_texture();
	data->ray = (t_ray *)malloc(sizeof(t_ray));
	if (!data->ray)
		ft_error_msg("ray allocation failed");
	data->mouse_x = WIDTH / 2;
	data->draw = (t_draw *)malloc(sizeof(t_draw));
	if (!data->draw)
	{
		free(data->ray);
		ft_error_msg("draw allocation failed");
	}
	return (true);
}
