/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:52:13 by abergman          #+#    #+#             */
/*   Updated: 2025/01/27 17:56:57 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	// int		length;
	if (!check_argv(argc, argv[1]))
		ft_error_msg("Incorrect input");
	if (!init_data(&data, argv[1]))
		free_exit(&data, "Initialization failed");
	if (!parsing(&data))
		free_exit(&data, "It's not ok");
	if (!ft_execution(&data))
		free_exit(&data, "It's not ok");
	// mlx_loop(data.mlx);
	// length = ft_strlen(str);
	// res = printf("%s, %d\n", str, length);
	return (0);
}
