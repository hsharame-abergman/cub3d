/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_mock.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:54:07 by abergman          #+#    #+#             */
/*   Updated: 2025/02/03 01:42:04 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

int	ft_create_mock(t_data *store)
{
	store->north = ft_init_texture();
	store->south = ft_init_texture();
	store->west = ft_init_texture();
	store->east = ft_init_texture();
	store->north->path = "textures/wolfenstein/blue_stone.xpm";
	store->south->path = "textures/wolfenstein/red_brick.xpm";
	store->west->path = "textures/wolfenstein/green_stone.xpm";
	store->east->path = "textures/wolfenstein/purple_stone.xpm";
	store->map->f_color = rgb_to_int(0, 0, 255);
	store->map->c_color = rgb_to_int(255, 0, 255);
	store->map->map_grid = malloc(sizeof(char *) * 7);
	store->map->map_grid[0] = "1111111111111111111111111";
	store->map->map_grid[1] = "1000000000000000000000001";
	store->map->map_grid[2] = "1000000000000000000000001";
	store->map->map_grid[3] = "1000000000000000000000001";
	store->map->map_grid[4] = "1000000000000000000000001";
	store->map->map_grid[5] = "1111111111111111111111111";
	store->map->map_grid[6] = NULL;
	store->map->height = 7;
	store->map->length = 25;
	store->map->longest_str = 26;
	store->map->map_height = 6; // real_height
	store->player = malloc(sizeof(t_player));
	store->player->y = 2.0099999999999998;
	store->player->x = 1.01;
	store->player->dir_x = 0;
	store->player->dir_y = -1;
	store->player->vector_x = 0.66000000000000003;
	store->player->vector_y = 0;
	return (0);
}
