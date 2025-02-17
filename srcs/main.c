/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:52:13 by abergman          #+#    #+#             */
/*   Updated: 2025/02/17 12:23:54 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char *argv[])
{
	t_data	store;

	if (!check_argv(argc, argv[1]))
		ft_error_msg("incorrect input");
	if (!init_data(&store, argv[1]) || !ft_check_size_of_window())
		free_exit(&store, "initialization failed");
	if (!parsing(&store))
		free_exit(&store, "The map is not valid");
	if (!ft_initialisation_main_texture(&store)
		|| !ft_initialisation_textures(&store))
		free_exit(&store, "window allocation failed");
	mlx_loop_hook(store.mlx, ft_draw, &store);
	mlx_hook(store.mlx_win, 2, 1L << 0, ft_keypress_handler, &store);
	mlx_hook(store.mlx_win, 6, 1L << 6, ft_mouse_handler, &store);
	mlx_hook(store.mlx_win, 17, 5, ft_destroy_handler, &store);
	mlx_loop(store.mlx);
	return (0);
}
