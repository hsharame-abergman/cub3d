/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:52:13 by abergman          #+#    #+#             */
/*   Updated: 2025/02/11 21:17:06 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

int	main(int argc, char *argv[])
{
	t_data	store;

	if (!check_argv(argc, argv[1]))
		ft_error_msg("incorrect input");
	if (!init_data(&store, argv[1]))
		free_exit(&store, "initialization failed");
	if (!parsing(&store))
		return (ft_putstr_fd("parsing failed\n", 2), 1);
	if (!ft_initialisation_main_texture(&store)
		|| !ft_initialisation_textures(&store))
	{
		ft_putstr_fd("parsing failed\n", 2);
		return (1);
	}
	if (!ft_initialisation_main_texture(&store))
	{
		free_exit(&store, NULL);
		ft_error_msg("window allocation failed");
	}
	
	mlx_loop_hook(store.mlx, ft_draw, &store);
	mlx_hook(store.mlx_win, 2, 1L << 0, ft_keypress_handler, &store);
	mlx_hook(store.mlx_win, 17, 5, ft_destroy_handler, &store);
	mlx_loop(store.mlx);
	return (0);
}
