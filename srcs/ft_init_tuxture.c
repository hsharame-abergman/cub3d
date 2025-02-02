/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tuxture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:12:16 by abergman          #+#    #+#             */
/*   Updated: 2025/02/02 18:16:13 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

t_texture	*ft_init_texture(void)
{
	t_texture	*new_texture;

	new_texture = (t_texture*)malloc(sizeof(t_texture) * 1);
	if (!new_texture)
		return (0);
	new_texture->address = NULL;
	new_texture->height = 0;
	new_texture->width = 0;
	new_texture->image = NULL;
	new_texture->path = NULL;
	new_texture->line_length = 0;
	new_texture->endian = 0;
	new_texture->bits_per_pixel = 0;
	return (new_texture);
}
