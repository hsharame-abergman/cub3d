/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:27:54 by hsharame          #+#    #+#             */
/*   Updated: 2025/01/03 16:21:27 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	ft_free_pointer(void *pointer)
{
	if (pointer != NULL)
	{
		free(pointer);
		pointer = NULL;
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] != NULL)
			ft_free_pointer(tab[i]);
		i++;
	}
	ft_free_pointer(tab);
}

bool	ft_isspace(char c)
{
	if ((c > 8 && c < 14) || c == ' ')
		return (true);
	else
		return (false);
}
