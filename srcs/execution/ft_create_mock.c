/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_mock.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:54:07 by abergman          #+#    #+#             */
/*   Updated: 2025/02/02 18:21:43 by abergman         ###   ########.fr       */
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
	return (0);

	store->map->map_grid[0] = "1111111111111111111111111";
	store->map->map_grid[1] = "1000000000000000000000001";
	store->map->map_grid[2] = "1000000000000000000000001";
	store->map->map_grid[3] = "1000000000000000000000001";
	store->map->map_grid[4] = "1000000000000000000000001";
	store->map->map_grid[5] = "1000000000000000000000001";
	store->map->map_grid[6] = "1111111111111111111111111";
	store->map->map_grid[7] = NULL;
	
}
