/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:27:51 by abergman          #+#    #+#             */
/*   Updated: 2025/01/30 15:41:09 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void ft_mlx_pixel_put(int x, int y, t_texture *texture, int color_bin)
{
    char *response;
    
    response = texture->address + (y * texture->line_length + x * (texture->bits_per_pixel / 8));
    *(unsigned int *)response = color_bin;
}
