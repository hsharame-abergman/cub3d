/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:56:23 by abergman          #+#    #+#             */
/*   Updated: 2025/02/20 19:54:02 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_mouse_handler(int x, int y, t_data *store)
{
	(void)y;
	if (x > store->player->mouse_x && x <= WIDTH)
	{
		ft_look_right(store);
	}
	else if (x < store->player->mouse_x && x >= 0)
	{
		ft_look_left(store);
	}
	store->player->mouse_x = x;
	return (1);
}
