/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:07:55 by hsharame          #+#    #+#             */
/*   Updated: 2024/12/17 16:10:27 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	ft_error_msg(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putchar_fd(str, 2);
	exit(1);
}
