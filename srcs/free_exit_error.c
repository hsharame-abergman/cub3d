/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:07:55 by hsharame          #+#    #+#             */
/*   Updated: 2024/12/31 12:07:38 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	free_exit(t_data *data, char *error)
{
	if (data->mlx_win)
		mlx_destroy_window(data->mlx);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
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
	ft_putchar_fd(str, 2);
	exit(1);
}
