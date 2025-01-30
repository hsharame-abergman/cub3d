/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:24:32 by abergman          #+#    #+#             */
/*   Updated: 2025/01/27 20:32:30 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h" 

void ft_move_player(t_data *data, int keynum)
{
    t_player *player;

    player = data->player;
    if (keynum == 13 || keynum == 119) // move forward
    {
        player->x += player->dir_x * 0.1;
        player->y += player->dir_y * 0.1;
    }
    if (keynum == 1 || keynum == 115) // move backward
    {
        player->x -= player->dir_x * 0.1;
        player->y -= player->dir_y * 0.1;
    }
    if (keynum == 0 || keynum == 97) // move left
    {
        player->x -= player->vector_y * 0.1;
        player->y += player->vector_x * 0.1;
    }
    if (keynum == 2 || keynum == 100) // move right
    {
        player->x += player->vector_y * 0.1;
        player->y -= player->vector_x * 0.1;
    }
}
