/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_floor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:44:07 by abergman          #+#    #+#             */
/*   Updated: 2025/01/30 15:33:02 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	ft_render_floor(t_data *store)
{
    int x;
    int y;
    int celing_color;
    int floor_color;

    y = 0;
    while(y < store->win_height)
    {
        x = 0;
        while (x < store->win_width)
        {
            if (y < store->win_height / 2)
                ft_mlx_pixel_put(x, y, store->map->main, store->map->c_color);
            else
                ft_mlx_pixel_put(x, y, store->map->main, store->map->f_color);
            x++;
        }
        y++;
    }
}
