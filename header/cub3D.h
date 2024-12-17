/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:47:52 by hsharame          #+#    #+#             */
/*   Updated: 2024/12/17 16:10:07 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include "../libft/libft.h"
//# include "../mlx/mlx.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

typedef struct	s_map
{
	int		fd;
	char	*filename;
	int		height;
	int		length;
}				t_map;

typedef struct	s_player
{
	int x;
	int y;
}				t_player;

typedef struct	s_data
{
	void		*mlx;
	void		*mlx_win;
	t_map		map;
	t_player	player;
}				t_data;

bool    check_argv(int argc, char *filename);
bool	check_extension(char *filename, char *extension);
void	ft_error_msg(char *str);
#endif
