/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:52:13 by abergman          #+#    #+#             */
/*   Updated: 2025/02/13 21:15:42 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

int	ft_resize_handler(int width, int height, t_data *data)
{
	const int	MIN_WIDTH = 480;
	const int	MAX_WIDTH = 1920;
	const int	MIN_HEIGHT = 360;
	const int	MAX_HEIGHT = 1080;

	printf("Debug: width=%d, height=%d\n", width, height);
	// Basic pointer validation
	if (width <= 0 || width > 1920 || height <= 0 || height > 1080)
	{
		printf("Debug: Invalid dimensions received: w=%d, h=%d\n", width,
			height);
		return (1);
	}
	if (!data)
	{
		printf("Debug: data is NULL\n");
		return (1);
	}
	// Check MLX pointers
	if (!data->mlx)
	{
		printf("Debug: data->mlx is NULL\n");
		return (1);
	}
	if (!data->mlx_win)
	{
		printf("Debug: data->win is NULL\n");
		return (1);
	}
	if (!data || !data->mlx || !data->mlx_win)
		return (1);
	// Set minimum and maximum window dimensions
	// Clamp dimensions
	width = (width < MIN_WIDTH) ? MIN_WIDTH : width;
	width = (width > MAX_WIDTH) ? MAX_WIDTH : width;
	height = (height < MIN_HEIGHT) ? MIN_HEIGHT : height;
	height = (height > MAX_HEIGHT) ? MAX_HEIGHT : height;
	data->win_width = width;
	data->win_height = height;
	// Recreate the image buffer if needed
	if (data->main)
		mlx_destroy_image(data->mlx, data->main);
	data->main = mlx_new_image(data->mlx, width, height);
	// Redraw the scene
	ft_draw(data);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	store;

	if (!check_argv(argc, argv[1]))
		ft_error_msg("incorrect input");
	if (!init_data(&store, argv[1]))
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
	mlx_hook(store.mlx_win, 22, 1L << 17, (int (*)(int, int,
				void *))ft_resize_handler, &store);
	mlx_loop(store.mlx);
	return (0);
}
