/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:20:27 by abergman          #+#    #+#             */
/*   Updated: 2025/02/14 00:12:42 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

static void	ft_move_forward(t_data *store)
{
	double new_x;
	double new_y;

	new_x = store->player->dir_x * PLAYERS_SPEED + 0.001;
	new_y = store->player->dir_y * PLAYERS_SPEED + 0.001;
	if (store->map->map_grid[(int)store->player->y][(int)(store->player->x
		+ store->player->dir_x * PLAYERS_SPEED + 0.001)] == '0')
		store->player->x += new_x;
	if (store->map->map_grid[(int)(store->player->y + store->player->dir_y
			* PLAYERS_SPEED + 0.001)][(int)store->player->x] == '0')
		store->player->y += new_y;
}

static void	ft_move_back(t_data *store)
{
	double new_x;
	double new_y;

	new_x = store->player->dir_x * PLAYERS_SPEED + 0.001;
	new_y = store->player->dir_y * PLAYERS_SPEED + 0.001;
	if (store->map->map_grid[(int)store->player->y][(int)(store->player->x
		- store->player->dir_x * PLAYERS_SPEED + 0.001)] == '0')
		store->player->x -= new_x;
	if (store->map->map_grid[(int)(store->player->y - store->player->dir_y
			* PLAYERS_SPEED + 0.001)][(int)store->player->x] == '0')
		store->player->y -= new_y;
}

static void	ft_move_left(t_data *store)
{
	double new_x;
	double new_y;

	new_x = store->player->vector_x * PLAYERS_SPEED + 0.001;
	new_y = store->player->vector_y * PLAYERS_SPEED + 0.001;
	if (store->map->map_grid[(int)store->player->y][(int)(store->player->x
		- store->player->vector_x * PLAYERS_SPEED + 0.001)] == '0')
		store->player->x -= new_x;
	if (store->map->map_grid[(int)(store->player->y - store->player->vector_y
			* PLAYERS_SPEED + 0.001)][(int)store->player->x] == '0')
		store->player->y -= new_y;
}

static void	ft_move_right(t_data *store)
{
	double new_x;
	double new_y;

	new_x = store->player->vector_x * PLAYERS_SPEED + 0.001;
	new_y = store->player->vector_y * PLAYERS_SPEED + 0.001;
	if (store->map->map_grid[(int)store->player->y][(int)(store->player->x
		+ store->player->vector_x * PLAYERS_SPEED + 0.001)] == '0')
		store->player->x += new_x;
	if (store->map->map_grid[(int)(store->player->y + store->player->vector_y
			* PLAYERS_SPEED + 0.001)][(int)store->player->x] == '0')
		store->player->y += new_y;
}

int	ft_keypress_handler(int keycode, t_data *store)
{
	if (keycode == 119)
		ft_move_forward(store);
	if (keycode == 115)
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
