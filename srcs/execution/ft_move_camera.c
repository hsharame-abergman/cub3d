/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:33:21 by abergman          #+#    #+#             */
/*   Updated: 2025/02/05 16:28:01 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	ft_look_right(t_data *store)
{
	double	olddirx;
	double	oldplanex;

	olddirx = store->player->dir_x;
	oldplanex = store->player->vector_x;
	store->player->dir_x = store->player->dir_x * cos(PLAYERS_SPEED)
		- store->player->dir_y * sin(PLAYERS_SPEED);
	store->player->dir_y = olddirx * sin(PLAYERS_SPEED) + store->player->dir_y
		* cos(PLAYERS_SPEED);
	store->player->vector_x = store->player->vector_x * cos(PLAYERS_SPEED)
		- store->player->vector_y * sin(PLAYERS_SPEED);
	store->player->vector_y = oldplanex * sin(PLAYERS_SPEED)
		+ store->player->vector_y * cos(PLAYERS_SPEED);
}

void	ft_look_left(t_data *store)
{
	double	olddirx;
	double	oldplanex;

	olddirx = store->player->dir_x;
	oldplanex = store->player->vector_x;
	store->player->dir_x = store->player->dir_x * cos(-PLAYERS_SPEED)
		- store->player->dir_y * sin(-PLAYERS_SPEED);
	store->player->dir_y = olddirx * sin(-PLAYERS_SPEED) + store->player->dir_y
		* cos(-PLAYERS_SPEED);
	store->player->vector_x = store->player->vector_x * cos(-PLAYERS_SPEED)
		- store->player->vector_y * sin(-PLAYERS_SPEED);
	store->player->vector_y = oldplanex * sin(-PLAYERS_SPEED)
		+ store->player->vector_y * cos(-PLAYERS_SPEED);
}
