/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:56:23 by abergman          #+#    #+#             */
/*   Updated: 2025/02/16 16:00:16 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_move_right(t_data *store)
{
	double		old_dir_x;
	double		old_vector_x;
	t_player	*p;
	double		speed;

	speed = ROTATE_SPEED;
	p = store->player;
	old_dir_x = p->dir_x;
	old_vector_x = p->vector_x;
	p->dir_x = p->dir_x * cos(-speed) - p->dir_y * sin(-speed);
	p->dir_y = old_dir_x * sin(-speed) + p->dir_y * cos(-speed);
	p->vector_x = p->vector_x * cos(-speed) - p->vector_y * sin(-speed);
	p->vector_y = old_vector_x * sin(-speed) + p->vector_y * cos(-speed);
	store->player = p;
}

void	ft_move_left(t_data *store)
{
	double		old_dir_x;
	double		old_vector_x;
	t_player	*p;
	double		speed;

	speed = ROTATE_SPEED;
	p = store->player;
	old_dir_x = p->dir_x;
	old_vector_x = p->vector_x;
	p->dir_x = p->dir_x * cos(speed) - p->dir_y * sin(speed);
	p->dir_y = old_dir_x * sin(speed) + p->dir_y * cos(speed);
	p->vector_x = p->vector_x * cos(speed) - p->vector_y * sin(speed);
	p->vector_y = old_vector_x * sin(speed) + p->vector_y * cos(speed);
	store->player = p;
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
