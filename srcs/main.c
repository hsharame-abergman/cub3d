/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:52:13 by abergman          #+#    #+#             */
/*   Updated: 2024/12/17 17:34:07 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

int	main(int argc, char *argv[])
{
	int		res;
	int		length;
	char	*str;
	void	*mlx;
	t_store	store;
	t_data	data;

	str = "Hello World!";
	if (!check_argv(argc, argv[1]))
		ft_error_msg("Incorrect input");
	if (!init_data(&data))
		ft_error_msg("Initialization failed");
	if (!parsing(&data))
		ft_error_msg("Parsing failed");
	if (!execution(&data))
		ft_error_msg("It's not ok");
	mlx = mlx_init();
	store.image = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	length = ft_strlen(str);
	res = printf("%s, %d\n", str, length);
	return (res);
}
