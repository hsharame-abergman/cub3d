/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:47:52 by hsharame          #+#    #+#             */
/*   Updated: 2025/02/20 11:24:43 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "X11/X.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_texture_type
{
	NORTH = 0,
	SOUTH,
	WEST,
	EAST
}					t_texture_type;

typedef struct s_keys
{
	bool			w;
	bool			a;
	bool			s;
	bool			d;
	bool			left;
	bool			right;
}					t_keys;

typedef struct s_ray
{
	double			camera;
	double			raydir_x;
	double			raydir_y;
	int				map_x;
	int				map_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	int				step_x;
	int				step_y;
	bool			hit;
	t_texture_type	side;
	double			walldist;
	int				start;
	int				end;
}					t_ray;

typedef struct s_draw
{
	int				lineh;
	double			wallx;
	int				texx;
	int				texy;
	double			texpos;
	double			step;
}					t_draw;

typedef struct s_texture
{
	char			*path;
	void			*image;
	int				bits_per_pixel;
	char			*address;
	int				width;
	int				height;
	int				line_length;
	int				endian;
}					t_texture;

typedef struct s_map
{
	int				fd;
	char			*filename;
	int				height;
	int				length;
	int				f_color;
	int				c_color;
	int				rgb[3];
	char			**initial_map;
	char			**map_grid;
	int				player;
}					t_map;

typedef struct s_player
{
	double			x;
	double			y;
	double			dir_x;
	double			dir_y;
	double			vector_x;
	double			vector_y;
	double			mouse_x;
	double			mouse_y;
}					t_player;

typedef struct s_sprite
{
	void			*image;
	char			*path;
	int				width;
	int				height;
	char			*address;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_sprite;

typedef struct s_animation
{
	t_sprite		*frames;
	int				frame_count;
	int				current_frame;
	int				frame_delay;
	int				frame_timer;
}					t_animation;

typedef struct s_data
{
	void			*mlx;
	void			*mlx_win;
	char			*filename;
	t_player		*player;
	t_ray			*ray;
	t_map			*map;
	t_texture		*north;
	t_texture		*south;
	t_texture		*west;
	t_texture		*east;
	t_texture		*main;
	t_draw			*draw;
	int				mouse_x;
	t_animation		*animation;
	t_keys			keys;
}					t_data;

# define WALL '1'
# define FLOOR '0'
# define HEIGHT 250
# define WIDTH 500
# define PLAYERS_SPEED 0.003
# define ROTATE_SPEED 0.07
# define DEFAULT_DOUBLE 0.01
# define FRAME_DELAY 10000
# define LOAD_SPRITES 0

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

t_texture			*ft_init_texture(void);
char				*ft_remove_newline(char *str);
int					ft_initialisation_textures(t_data *store);
int					ft_keypress(int keynum, t_data *data);
int					ft_initialisation_main_texture(t_data *store);
int					ft_destroy_handler(t_data *data);
void				ft_clear_window(t_data *store, t_texture *main);
void				ft_mlx_pixel_put(int x, int y, t_texture *t, int color_bin);
int					ft_draw(t_data *store);
/* ray casting */
void				ft_init_drawing_params(t_data *store, int x);
void				ft_calculate_start_step(t_data *store);
void				ft_calculate_distance_to_wall(t_data *store);
void				ft_digital_differential_analyzer(t_data *store);
void				ft_compute_wall_projection(t_data *store);
/* camera */
void				ft_look_right(t_data *store);
void				ft_look_left(t_data *store);
t_draw				*ft_init_draw(void);
void				ft_mini_map(t_data *store);
int					ft_mouse_handler(int x, int y, t_data *store);
void				ft_draw_line_of_texture(t_data *store, int x);
unsigned int		ft_get_tetxure_color(t_data *store);
void				ft_texture_params_init(t_data *store);
int					ft_release_key(int keynum, t_data *data);
void				ft_move_forward(t_data *store);
void				ft_move_back(t_data *store);
void				ft_move_left(t_data *store);
void				ft_move_right(t_data *store);

void				find_player(t_data *data, t_map *map);
bool				check_argv(int argc, char *filename);
bool				ft_check_size_of_window(void);
bool				init_data(t_data *data, char *file);
bool				check_extension(char *filename, char *extension);
void				ft_error_msg(char *str);
void				free_exit(t_data *data, char *error);
bool				parsing(t_data *data);
bool				map_is_valid(t_data *data, t_map *map);
bool				extract_info(t_map *map);
void				fill_copy_lines(t_map *map);
int					rgb_to_int(int r, int g, int b);
bool				check_textures_colors(t_data *data, t_map *map);
int					check_number(char **lines);
bool				find_grid(t_map *map, char **dirty_map);
void				display_grid(char **grid);
bool				find_colors(t_map *map);
void				free_tab(char **tab);
bool				ft_isspace(char c);
bool				check_top_bottom_walls(char *str);
bool				check_no_output(char **map);
int					is_player(int c);
bool				check_grid_map(t_map *map);
bool				check_size_map(t_map *map);
bool				check_walls(t_map *map);
bool				check_player_other_char(t_map *map);
int					rgb_to_int(int r, int g, int b);

t_player			*init_player(void);

int					ft_initialisation_sprites(t_data *store, int h, int w);
void				ft_update_sprite_animation(t_animation *animation);

#endif
