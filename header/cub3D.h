/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:47:52 by hsharame          #+#    #+#             */
/*   Updated: 2024/12/31 11:57:54 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
//# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_map
{
	int			fd;
	char		*filename;
	int			height;
	int			length;
}				t_map;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		vector_x;
	double		vector_y;
}				t_player;

typedef struct s_ray
{
	double		dir_x;
	double		dir_y;
}				t_ray;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	int			win_width;
	int			win_height;
	char		*filename;
	t_map		*map;
	t_player	*player;
	t_ray		*ray;
}				t_data;

bool			check_argv(int argc, char *filename);
bool			check_extension(char *filename, char *extension);
void			ft_error_msg(char *str);

#endif
