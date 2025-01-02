/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:29:48 by hsharame          #+#    #+#             */
/*   Updated: 2024/12/31 12:43:34 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

bool    parsing(t_data *data)
{
    if (!map_is_valid(data->map))
        free_exit(data, "The map is not valid");
    return (true);
}
