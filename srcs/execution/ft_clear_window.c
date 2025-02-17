/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:18:43 by abergman          #+#    #+#             */
/*   Updated: 2025/02/17 17:11:20 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_clear_window(t_data *store, t_texture *main)
{
	free_exit(store, NULL);
	if (main->image)
		mlx_destroy_image(store->mlx, main->image);
	if (store->mlx_win)
		mlx_destroy_window(store->mlx, store->mlx_win);
	if (store->mlx)
	{
		mlx_destroy_display(store->mlx);
		free(store->mlx);
	}
}
