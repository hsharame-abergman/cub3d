/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:18:43 by abergman          #+#    #+#             */
/*   Updated: 2025/02/05 01:37:15 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	ft_clear_window(t_data *store, t_texture *main)
{
	ft_free_prev(store);
	if (main->image)
		mlx_destroy_image(store->mlx, main->image);
	if (main)
		mlx_destroy_window(store->mlx, store->mlx_win);
}
