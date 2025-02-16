/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:20:27 by abergman          #+#    #+#             */
/*   Updated: 2025/02/16 16:09:53 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* Checking for a collision with a wall when moving forward.  */
/* If the player has not encountered the wall, his coordinates are updated. */

static void	ft_move_forward(t_data *store)
{
	double		new_x;
	double		new_y;
	t_player	*p;
	char		**grid;
	double		speed;

	grid = store->map->map_grid;
	speed = PLAYERS_SPEED;
	p = store->player;
	new_x = p->dir_x * speed;
	new_y = p->dir_y * speed;
	if (grid[(int)p->y][(int)(p->x + p->dir_x * speed)] != WALL)
		p->x += new_x;
	if (grid[(int)(p->y + p->dir_y * speed)][(int)p->x] != WALL)
		p->y += new_y;
	store->player = p;
}

static void	ft_move_back(t_data *store)
{
	double		new_x;
	double		new_y;
	t_player	*p;
	char		**grid;
	double		speed;

	grid = store->map->map_grid;
	speed = PLAYERS_SPEED;
	p = store->player;
	new_x = p->dir_x * speed;
	new_y = p->dir_y * speed;
	if (grid[(int)p->y][(int)(p->x - p->dir_x * speed)] != WALL)
		p->x -= new_x;
	if (grid[(int)(p->y - p->dir_y * speed)][(int)p->x] != WALL)
		p->y -= new_y;
	store->player = p;
}

static void	ft_move_left(t_data *store)
{
	double		new_x;
	double		new_y;
	t_player	*p;
	char		**grid;
	double		speed;

	grid = store->map->map_grid;
	speed = PLAYERS_SPEED;
	p = store->player;
	new_x = p->vector_x * speed;
	new_y = p->vector_y * speed;
	if (grid[(int)p->y][(int)(p->x - p->vector_x * speed)] == '0')
		p->x -= new_x;
	if (grid[(int)(p->y - p->vector_y * speed)][(int)p->x] == '0')
		p->y -= new_y;
	store->player = p;
}

static void	ft_move_right(t_data *store)
{
	double		new_x;
	double		new_y;
	t_player	*p;
	char		**grid;
	double		speed;

	grid = store->map->map_grid;
	speed = PLAYERS_SPEED;
	p = store->player;
	new_x = p->vector_x * speed;
	new_y = p->vector_y * speed;
	if (grid[(int)p->y][(int)(p->x + p->vector_x * speed)] == '0')
		p->x += new_x;
	if (grid[(int)(p->y + p->vector_y * speed)][(int)p->x] == '0')
		p->y += new_y;
	store->player = p;
}

int	ft_keypress_handler(int keycode, t_data *store)
{
	if (keycode == 119 || keycode == 65362)
		ft_move_forward(store);
	if (keycode == 115 || keycode == 65364)
		ft_move_back(store);
	if (keycode == 97)
		ft_move_left(store);
	if (keycode == 100)
		ft_move_right(store);
	if (keycode == 65361)
		ft_look_left(store);
	if (keycode == 65363)
		ft_look_right(store);
	if (keycode == 65307)
	{
		ft_clear_window(store, store->main);
		exit(0);
	}
	return (1);
}
