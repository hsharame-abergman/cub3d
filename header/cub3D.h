/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:47:52 by hsharame          #+#    #+#             */
/*   Updated: 2025/01/27 17:38:29 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
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

typedef enum e_texture_type
{
	NORTH = 0,
	SOUTH,
	WEST,
	EAST
}				t_texture_type;

typedef struct s_texture
{
	char		*path;
	void		*image;
	int			bits_per_pixel;
	char		*address;
	int			width;
	int			height;
	int			line_length;
	int			endian;
}				t_texture;

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
	t_texture	*main;
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

# define WIDTH_TEXTURE 10000;
# define HEIGHT_TEXTURE 10000;

typedef struct s_raycasting
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_raycasting;

t_texture		*ft_init_texture(void);
int				ft_execution(t_data *store);
int				ft_error_handler(char *str, int res);
int				ft_initialisation_minilibx(t_data *store);
int				ft_initialisation_textures(t_data *store);
int				ft_initialisation_window(t_data *data);
int				ft_keypress_handler(int keynum, t_data *data);
int				ft_initialisation_main_texture(t_data *store, t_texture *main);

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
bool			check_top_bottom_walls(char *str);
bool			check_no_output(char **map);
int				is_player(int c);
bool			check_grid_map(t_map *map);
bool			check_size_map(t_map *map);
bool			check_walls(t_map *map);
bool			check_player_other_char(t_map *map);

#endif
