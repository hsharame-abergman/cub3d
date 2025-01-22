/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:24:47 by abergman          #+#    #+#             */
/*   Updated: 2025/01/22 16:28:34 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

/*
    посмотри мою функцию void ft_error_msg(char *str) в файле free_exit_error.c
    они одинаковые 
*/
void    ft_error_handler(char *str, int res)
{
    ft_putendl_fd("Error\n", 2);
    ft_putendl_fd(str, 2);
}
