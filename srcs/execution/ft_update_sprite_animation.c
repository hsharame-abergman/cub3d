/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_sprite_animation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:24:31 by abergman          #+#    #+#             */
/*   Updated: 2025/02/18 10:26:22 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_update_sprite_animation(t_animation *animation)
{
	animation->frame_timer++;
	if (animation->frame_timer >= animation->frame_delay)
	{
		animation->frame_timer = 0;
		animation->current_frame++;
		if (animation->current_frame >= animation->frame_count)
			animation->current_frame = 0;
	}
}
