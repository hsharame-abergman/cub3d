/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:14:32 by hsharame          #+#    #+#             */
/*   Updated: 2025/02/17 12:23:32 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

bool	ft_check_size_of_window(void)
{
	if (WIDTH >= 1920 || HEIGHT >= 1080)
		return (false);
	if (HEIGHT <= 100 || WIDTH <= 100)
		return (false);
	return (true);
}

bool	check_argv(int argc, char *filename)
{
	int	fd;

	if (argc != 2)
		return (false);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (false);
	close (fd);
	if (!check_extension(filename, ".cub"))
		return (false);
	return (true);
}

bool	check_extension(char *filename, char *extension)
{
	int	i;
	int	j;

	i = ft_strlen(filename) - 1;
	j = 3;
	while (j >= 0)
	{
		if (filename[i] != extension[j])
			return (false);
		i--;
		j--;
	}
	return (true);
}
