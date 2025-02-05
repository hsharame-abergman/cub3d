/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:27:54 by hsharame          #+#    #+#             */
/*   Updated: 2025/02/05 01:57:49 by abergman         ###   ########.fr       */
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

char	**remove_newlines(char **str)
{
	char **str2;
	int i;
	int j;
	int k;

	i = 0;
	while (str[i])
		i++;
	str2 = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (str[i])
	{
		j = 0;
		k = 0;
		while (str[i][j])
		{
			if (str[i][j] != '\n')
				k++;
			j++;
		}
		str2[i] = (char *)malloc(sizeof(char) * (k + 1));
		j = 0;
		k = 0;
		while (str[i][j])
		{
			if (str[i][j] != '\n')
				str2[i][k++] = str[i][j];
			j++;
		}
		str2[i][k] = '\0';
		i++;
	}
	str2[i] = NULL;
	return (str2);
}
