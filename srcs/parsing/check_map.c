/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:40:58 by hsharame          #+#    #+#             */
/*   Updated: 2024/12/31 12:50:18 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

bool    map_is_valid(t_map *map)
{
    if (!check_map_size(map))
        return (false);
    if (!check_map_walls(map))
        return (false);
    if (!check_map_texture_colors(map))
        return (false);
    if (!check_map_player_positon(map))
        return (false);
}