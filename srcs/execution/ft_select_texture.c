/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:36:38 by abergman          #+#    #+#             */
/*   Updated: 2025/01/31 19:09:44 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

t_texture *ft_select_texture(t_data *store, t_ray *ray)
{
    if (ray->side == 0)
    {
        if (ray->dir_x > 0)
            return (store->west);
        else
            return (store->east);
    }
    else
    {
        if (ray->dir_y > 0)
            return (store->north);
        else
            return (store->south);
    }
}
