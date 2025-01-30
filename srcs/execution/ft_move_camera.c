/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:33:21 by abergman          #+#    #+#             */
/*   Updated: 2025/01/27 20:46:34 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void    ft_move_camera(t_data *store, int keynum)
{
    t_player *player;

    player = store->player;
    if (keynum == 123 || keynum == 65361) // move left
    {
        player->dir_x = player->dir_x * cos(-0.1) - player->dir_y * sin(-0.1);
        player->dir_y = player->dir_x * sin(-0.1) + player->dir_y * cos(-0.1);
        player->vector_x = player->vector_x * cos(-0.1) - player->vector_y * sin(-0.1);
        player->vector_y = player->vector_x * sin(-0.1) + player->vector_y * cos(-0.1);
    }
    if (keynum == 124 || keynum == 65363) // move right
    {
        player->dir_x = player->dir_x * cos(0.1) - player->dir_y * sin(0.1);
        player->dir_y = player->dir_x * sin(0.1) + player->dir_y * cos(0.1);
        player->vector_x = player->vector_x * cos(0.1) - player->vector_y * sin(0.1);
        player->vector_y = player->vector_x * sin(0.1) + player->vector_y * cos(0.1);
    }
}
