/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:47:37 by abergman          #+#    #+#             */
/*   Updated: 2024/05/30 20:29:34 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*res;
	int		length;
	int		index;

	index = 0;
	length = ft_strlen((char *)s);
	res = malloc(sizeof(*s) * length + 1);
	if (!res)
		return (NULL);
	while (index <= length)
	{
		res[index] = s[index];
		index++;
	}
	res[index] = '\0';
	return (res);
}
