/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:31:03 by abergman          #+#    #+#             */
/*   Updated: 2025/01/25 23:21:58 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

int			ft_clear(t_data *store)
{
	(void)store;
	return (0);
}

void		ft_clear_window(t_data *store);
void		ft_render_floor(t_data *store);
void		ft_render_frame(t_data *store);
void		ft_move_player(t_data *store, int keynum);
void		ft_move_camera(t_data *store, int keynum);
int			ft_initialisation_main_texture(t_data *store, t_texture *main);

static int	ft_destroy_handler(t_data *data)
{
	ft_clear(data);
	exit(1);
}

int	ft_execution(t_data *store)
{
	int			result;
	t_texture	main;

	result = 0;
	if (ft_initialisation_minilibx(store))
		return (ft_error_handler("initialisation minilibx is failed", 1), 1);
	if (ft_initialisation_textures(store))
		return (ft_error_handler("initialisation minilibx is failed", 1), 1);
	if (ft_initialisation_window(store))
		return (ft_error_handler("initialisation window is faled", 1), 1);
	if (ft_initialisation_main_texture(store, &main))
		return (ft_error_handler("Main image not installed, fatal error", 1),
			1);
	store->map->main = &main;
	ft_render_floor(store);
	ft_render_frame(store);
	mlx_put_image_to_window(store->mlx, store->mlx_win, main.image, 0, 0);
	mlx_hook(store->mlx_win, 2, 1L << 0, ft_keypress_handler, store);
	mlx_hook(store->mlx_win, 17, 1L << 4, ft_destroy_handler, store);
	mlx_loop(store->mlx_win);
	return (result);
}
