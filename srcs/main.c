/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:52:13 by abergman          #+#    #+#             */
/*   Updated: 2025/02/03 11:27:19 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (!check_argv(argc, argv[1]))
		ft_error_msg("Incorrect input");
	if (!init_data(&data, argv[1]))
		free_exit(&data, "Initialization failed");
	if (!parsing(&data))
		ft_putstr_fd("Parsing failed\n", 2);
			
	/*ft_create_mock(&data);
	
	if (ft_execution(&data))
		free_exit(&data, "It's not ok");*/
	return (0);
}
