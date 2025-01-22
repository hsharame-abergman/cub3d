/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:47:52 by hsharame          #+#    #+#             */
/*   Updated: 2025/01/22 15:14:10 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../mlx/mlx.h"
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
# include "../header/execution.h"

typedef enum e_texture_type
{
	NORTH = 0,
	SOUTH,
	WEST,
	EAST
}			t_texture_type;

typedef struct s_map
{
	int			fd;
	char		*filename;
	int			height;
	int			length;
	int			f_color;
	int			c_color;
	int			rgb[3];
	char		**initial_map;
	char		**map_grid;
	int			player;
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
	t_player	*player;
	t_ray		*ray;
	t_map		*map;
	t_texture	*north;
	t_texture	*south;
	t_texture	*west;
	t_texture	*east;
}				t_data;

bool			check_argv(int argc, char *filename);
bool			init_data(t_data *data, char *file);
bool			check_extension(char *filename, char *extension);
void			ft_error_msg(char *str);
void			free_exit(t_data *data, char *error);
bool			parsing(t_data *data);
bool			map_is_valid(t_data *data, t_map *map);
bool			extract_info(t_map *map);
void			fill_copy_lines(t_map *map);
int				rgb_to_int(int r, int g, int b);
bool			check_textures_colors(t_data *data, t_map *map);
bool			find_grid(t_map *map, char **dirty_map);
bool			find_colors(t_map *map);
void			free_tab(char **tab);
bool			ft_isspace(char c);

#endif
