/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialisation_minilibx.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:29:05 by abergman          #+#    #+#             */
/*   Updated: 2025/02/02 15:26:12 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

int ft_initialisation_minilibx(t_data *store)
{
    store->mlx = mlx_init();
    if (!store->mlx)
        ft_error_handler("miniLibX can't initialised", 1);
    store->win_height = 600;
    store->win_width = 800;
    store->mlx_win = NULL;
    return (0);
}
