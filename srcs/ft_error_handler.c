/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:24:47 by abergman          #+#    #+#             */
/*   Updated: 2025/01/21 17:40:50 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void    ft_error_handler(char *str, int res)
{
    ft_putendl_fd("Error\n", 2);
    ft_putendl_fd(str, 2);
}
