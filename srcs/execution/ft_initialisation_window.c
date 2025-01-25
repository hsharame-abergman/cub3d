/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialisation_window.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:58:17 by abergman          #+#    #+#             */
/*   Updated: 2025/01/25 22:43:17 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

int	ft_initialisation_window(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx, data->win_width, data->win_height,
			"cub3D");
	if (!data->mlx_win)
		return (ft_error_handler("Windows not created", 1), 1);
    return (0);
}
