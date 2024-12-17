/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:52:13 by abergman          #+#    #+#             */
/*   Updated: 2024/12/17 16:36:46 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

int	main(void)
{
	int		res;
	int		length;
	char	*str;
	void	*mlx;
	t_store	store;

	str = "Hello World!";
	mlx = mlx_init();
	store.image = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	length = ft_strlen(str);
	res = printf("%s, %d\n", str, length);
	return (res);
/*   Updated: 2024/12/17 16:15:26 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3D.h"

int	main(int argc, char *argv[]) 
{
	int res;
	int a;
	t_data	data;

	if (!check_argv(argc, argv[1]))
		ft_error_msg("Incorrect input");
	if (!init_data(&data))
		ft_error_msg("Initialization failed");
	if (!parsing(&data))
		ft_error_msg("Parsing failed");
	if (!execution(&data))
		ft_error_msg("It's not ok");
	res = printf("Hello World!\n");
	return (0);
}
