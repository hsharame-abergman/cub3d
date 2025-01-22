/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:31:03 by abergman          #+#    #+#             */
/*   Updated: 2025/01/22 13:43:11 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"
#include "../../header/execution.h"

int	ft_execution(t_data *store)
{
	int			result;
	t_texture	main;

	if (ft_initialisation_minilibx(store))
		return (ft_error_handler("initialisation minilibx is failed", 1), 1);
	if (ft_initialisation_textures(store))
		return (ft_error_handler("initialisation minilibx is failed", 1), 1);
	(void)main;
	result = 0;
	return (0);
}
