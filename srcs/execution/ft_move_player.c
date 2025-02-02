/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:24:32 by abergman          #+#    #+#             */
/*   Updated: 2025/02/02 18:48:08 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	ft_move_forward(t_player *player, t_map *map)
{
	int	new_x;
	int	new_y;

	new_x = player->x + player->dir_x * 0.01;
	new_y = player->y + player->dir_y * 0.01;
	if (new_x >= 0 && new_x < (int)map->longest_str && new_y >= 0
		&& new_y < map->map_height)
	{
		if (map->map_grid[(int)player->y][(int)new_x] == '0')
		{
			player->x += player->dir_x * 0.01;
		}
		if (map->map_grid[(int)new_y][(int)player->x] == '0')
		{
			player->y += player->dir_y * 0.01;
		}
	}
}

void	ft_move_backward(t_player *player, t_map *map)
{
	int	new_x;
	int	new_y;

	new_x = player->x - player->dir_x * 0.01;
	new_y = player->y - player->dir_y * 0.01;
	if (new_x >= 0 && new_x < (int)map->longest_str && new_y >= 0
		&& new_y < map->map_height)
	{
		if (map->map_grid[(int)player->y][(int)new_x] == '0')
		{
			player->x -= player->dir_x * 0.01;
		}
		if (map->map_grid[(int)new_y][(int)player->x] == '0')
		{
			player->y -= player->dir_y * 0.01;
		}
	}
}

void	ft_move_left(t_player *player, t_map *map)
{
	int	new_x;
	int	new_y;

	new_x = player->x - player->vector_x * 0.01;
	new_y = player->y - player->vector_y * 0.01;
	if (new_x >= 0 && new_x < (int)map->longest_str && new_y >= 0
		&& new_y < map->map_height)
	{
		if (map->map_grid[(int)player->y][(int)new_x] == '0')
		{
			player->x -= player->vector_x * 0.01;
		}
		if (map->map_grid[(int)new_y][(int)player->x] == '0')
		{
			player->y -= player->vector_y * 0.01;
		}
	}
}

void	ft_move_right(t_player *player, t_map *map)
{
	int	new_x;
	int	new_y;

	new_x = player->x + player->vector_x * 0.01;
	new_y = player->y + player->vector_y * 0.01;
	if (new_x >= 0 && new_x < (int)map->longest_str && new_y >= 0
		&& new_y < map->map_height)
	{
		if (map->map_grid[(int)player->y][(int)new_x] == '0')
		{
			player->x += player->vector_x * 0.01;
		}
		if (map->map_grid[(int)new_y][(int)player->x] == '0')
		{
			player->y += player->vector_y * 0.01;
		}
	}
}

void	ft_move_player(t_data *data, int keynum)
{
	t_player	*player;

	player = data->player;
	if (keynum == 13 || keynum == 119) // move forward
	{
		ft_move_forward(player, data->map);
	}
	if (keynum == 1 || keynum == 115) // move backward
	{
		ft_move_backward(player, data->map);
	}
	if (keynum == 0 || keynum == 97) // move left
	{
		ft_move_left(player, data->map);
	}
	if (keynum == 2 || keynum == 100) // move right
	{
		ft_move_right(player, data->map);
	}
}
