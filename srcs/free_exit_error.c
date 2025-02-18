/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:07:55 by hsharame          #+#    #+#             */
/*   Updated: 2025/02/18 12:44:16 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	ft_free_texture(t_texture *texture, void *mlx)
{
	if (texture->image)
		mlx_destroy_image(mlx, texture->image);
	texture->image = NULL;
	if (texture->path)
		free(texture->path);
	texture->path = NULL;
	free(texture);
}

void	ft_free_textures(t_data *data)
{
	if (data->north)
		ft_free_texture(data->north, data->mlx);
	if (data->south)
		ft_free_texture(data->south, data->mlx);
	if (data->west)
		ft_free_texture(data->west, data->mlx);
	if (data->east)
		ft_free_texture(data->east, data->mlx);
	if (data->main)
		ft_free_texture(data->main, data->mlx);
}

void	free_exit(t_data *data, char *error)
{
	if (!data)
		return ;
	ft_free_textures(data);
	if (data->player)
		free(data->player);
	if (data->ray)
		free(data->ray);
	if (data->draw)
		free(data->draw);
	if (data->map->initial_map)
		free_tab(data->map->initial_map);
	if (data->map->map_grid)
		free_tab(data->map->map_grid);
	if (data->map)
		free(data->map);
	if (error)
		ft_error_msg(error);
}

void	ft_error_msg(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}
