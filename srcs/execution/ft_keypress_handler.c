/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:20:27 by abergman          #+#    #+#             */
/*   Updated: 2025/01/25 23:22:15 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

int	ft_keypress_handler(int keynum, t_data *data)
{
	if (keynum == 53 || keynum == 65307)
		ft_destroy_handler(data);
	ft_clear_window(data);
	ft_move_player(data, keynum);
	ft_move_camera(data, keynum);
	ft_render_frame(data);
	return (keynum);
}
