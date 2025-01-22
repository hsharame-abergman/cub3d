/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:52:13 by abergman          #+#    #+#             */
/*   Updated: 2025/01/21 17:04:15 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"
#include "../header/execution.h"

int	main(int argc, char *argv[])
{
	// int		length;
	char	*str;
	t_data	data;

	str = "Hello World!";
	if (!check_argv(argc, argv[1]))
		ft_error_msg("Incorrect input");
	if (!init_data(&data, argv[1]))
		free_exit(&data, "Initialization failed");
	parsing(&data);
	if (!ft_execution(&data))
		free_exit(&data, "It's not ok");
	mlx_loop(data.mlx);
	// length = ft_strlen(str);
	//res = printf("%s, %d\n", str, length);
	return (0);
}
