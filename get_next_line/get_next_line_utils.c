/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:44:51 by hsharame          #+#    #+#             */
/*   Updated: 2025/02/12 16:45:07 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_newline(const char *saved)
{
	char	*ptr;

	ptr = (char *)saved;
	while (*ptr)
	{
		if (*ptr == '\n')
			return (1);
		ptr++;
	}
	return (0);
}
