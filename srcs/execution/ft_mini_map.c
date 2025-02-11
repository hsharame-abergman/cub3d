/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:15:27 by abergman          #+#    #+#             */
/*   Updated: 2025/02/11 21:49:59 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	ft_draw_square(int x, int y, t_texture *t, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			ft_mlx_pixel_put(x * 5 + i + 17, y * 5 + j + 17, t, color);
			j++;
		}
		i++;
	}
}

void	ft_draw_player(t_data *store, int color)
{
	ft_draw_square(store->player->x, store->player->y, store->main, color);
}

void	ft_draw_map_element(char element, int x, int y, t_texture *t)
{
    if (element == '1')
        ft_draw_square(x, y, t, 0x00FF0000);
    else if (element == '0')
        ft_draw_square(x, y, t, 0x000000FF);
}

void	ft_mini_map(t_data *store)
{
    int	i;
    int	j;

    i = -1;
    while (store->map->map_grid[++i])
    {
        j = -1;
        while (store->map->map_grid[i][++j])
            ft_draw_map_element(store->map->map_grid[i][j], j, i, store->main);
    }
    ft_draw_player(store, 0x0000FF00);
}
