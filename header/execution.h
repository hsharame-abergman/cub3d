/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:27:16 by abergman          #+#    #+#             */
/*   Updated: 2025/01/21 17:36:48 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../header/cub3D.h"

typedef struct s_raycasting
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}			t_raycasting;

typedef struct s_texture
{
}			t_texture;

int			ft_execution(t_data *data);
int			ft_error_handler(char *str, int res);
int			ft_initialisation_minilibx(t_data *store);

#endif
