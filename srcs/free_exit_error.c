/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:07:55 by hsharame          #+#    #+#             */
/*   Updated: 2025/02/02 14:21:19 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	ft_free_main_texture(t_data *data)
{
/* 	if (data->map->main->image)
		mlx_destroy_image(data->mlx, data->map->main->image); */
	free(data->map->main->image);
	free(data->map->main);
	data->map->main->image = NULL;
	data->map->main = NULL;
}

void	ft_free_texture(t_texture *texture, void *mlx)
{
	if (texture->image)
		mlx_destroy_image(mlx, texture->image);
	if (texture->path)
		free(texture->path);
	free(texture);
}

void	ft_free_textures(t_data *data)
{
	ft_free_texture(data->north, data->mlx);
	ft_free_texture(data->south, data->mlx);
	ft_free_texture(data->west, data->mlx);
	ft_free_texture(data->east, data->mlx);
}

void	free_exit(t_data *data, char *error)
{
	if (!data)
		return ;
	ft_free_textures(data);
	if (data->map->main)
		ft_free_main_texture(data);
	if (data->map)
		free(data->map);
	if (data->player)
		free(data->player);
	if (data->ray)
		free(data->ray);
	if (error)
		ft_error_msg(error);
	exit(0);
}

void	ft_error_msg(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}
