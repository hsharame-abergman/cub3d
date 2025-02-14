/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:56:23 by abergman          #+#    #+#             */
/*   Updated: 2025/02/14 22:31:29 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	ft_move_right(t_data *store)
{
	double	old_dir_x;
	double	old_vector_x;

	old_dir_x = store->player->dir_x;
	old_vector_x = store->player->vector_x;
	store->player->dir_x = store->player->dir_x * cos(-ROTATE_SPEED)
		- store->player->dir_y * sin(-ROTATE_SPEED);
	store->player->dir_y = old_dir_x * sin(-ROTATE_SPEED) + store->player->dir_y
		* cos(-ROTATE_SPEED);
	store->player->vector_x = store->player->vector_x * cos(-ROTATE_SPEED)
		- store->player->vector_y * sin(-ROTATE_SPEED);
	store->player->vector_y = old_vector_x * sin(-ROTATE_SPEED)
		+ store->player->vector_y * cos(-ROTATE_SPEED);
}

void	ft_move_left(t_data *store)
{
	double	old_dir_x;
	double	old_vector_x;

	old_dir_x = store->player->dir_x;
	old_vector_x = store->player->vector_x;
	store->player->dir_x = store->player->dir_x * cos(ROTATE_SPEED)
		- store->player->dir_y * sin(ROTATE_SPEED);
	store->player->dir_y = old_dir_x * sin(ROTATE_SPEED) + store->player->dir_y
		* cos(ROTATE_SPEED);
	store->player->vector_x = store->player->vector_x * cos(ROTATE_SPEED)
		- store->player->vector_y * sin(ROTATE_SPEED);
	store->player->vector_y = old_vector_x * sin(ROTATE_SPEED)
		+ store->player->vector_y * cos(ROTATE_SPEED);
}

int	ft_mouse_handler(int x, int y, t_data *store)
{
	(void)y;
	if (x > store->player->mouse_x && x <= WIDTH)
	{
		ft_move_left(store);
	}
	else if (x < store->player->mouse_x && x >= 0)
	{
		ft_move_right(store);
	}
	store->player->mouse_x = x;
	return (1);
}
