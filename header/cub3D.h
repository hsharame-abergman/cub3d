/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:47:52 by hsharame          #+#    #+#             */
/*   Updated: 2025/02/05 21:36:45 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_ray
{
	double		camera;
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		walldist;
	int			start;
	int			end;
}				t_ray;

typedef struct s_draw
{
	int			lineh;
	double		wallx;
	int			texx;
	int			texy;
	double		texpos;
	double		step;
}				t_draw;

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
typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	char		*filename;
	t_player	*player;
	t_ray		*ray;
	t_map		*map;
	t_texture	*north;
	t_texture	*south;
	t_texture	*west;
	t_texture	*east;
	t_texture	*main;
	t_draw		*draw;
	int			mouse_x;
}				t_data;

# define WIDTH_TEXTURE 64
# define HEIGHT_TEXTURE 64
# define HEIGHT 200
# define WIDTH 300
# define PLAYERS_SPEED 0.15
# define ROTATE_SPEED 0.010

t_texture		*ft_init_texture(void);
char			*ft_remove_newline(char *str);
int				ft_initialisation_textures(t_data *store);
int				ft_keypress_handler(int keynum, t_data *data);
int				ft_initialisation_main_texture(t_data *store);
int				ft_destroy_handler(t_data *data);
void			ft_clear_window(t_data *store, t_texture *main);
void			ft_mlx_pixel_put(int x, int y, t_texture *t, int color_bin);
int				ft_draw(t_data *store);
void			ft_init_drawing(t_data *store, int x);
void			ft_calculate_step(t_data *store);
void			ft_calculate_distance(t_data *store);
void			ft_dda(t_data *store);
void			ft_calculate_stripe(t_data *store);
void			ft_look_right(t_data *store);
void			ft_look_left(t_data *store);
t_draw			*ft_init_draw(void);

void			find_player(t_data *data, t_map *map);
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
int				rgb_to_int(int r, int g, int b);

t_player		*init_player(void);

#endif
