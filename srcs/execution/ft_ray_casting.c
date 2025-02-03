/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:33:15 by abergman          #+#    #+#             */
/*   Updated: 2025/02/03 01:24:02 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

double	ft_fabs(double num)
{
	if (num < 0)
		return (-num);
	return (num);
}

void	ft_initialisation_ray(t_ray *ray, t_player *player, int x,
		int win_width)
{
	double	camera_x;

	camera_x = 2 * x / (double)win_width - 1;
	ray->ray_dir_x = player->dir_x + player->vector_x * camera_x;
	ray->ray_dir_y = player->dir_y + player->vector_y * camera_x;
	ray->map_x = (int)player->x;
	ray->map_y = (int)player->y;
	ray->delta_dist_x = ft_fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = ft_fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

void	ft_calculate_step_and_side_dist(t_ray *ray, t_player *player)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->y) * ray->delta_dist_y;
	}
}

void	ft_calculate_perpendicular_wall_distance(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - player->x + (1 - ray->step_x) / 2)
			/ ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - player->y + (1 - ray->step_y) / 2)
			/ ray->ray_dir_y;
}

void	ft_perform_digital_differential_analysis(t_ray *ray, t_map *map)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0; // (ray->ray_dir_x < 0) ? WEST : EAST;
							// This is a bug
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1; // (ray->ray_dir_y < 0) ? SOUTH : NORTH;
							// This is a bug
		}
		if (map->map_grid[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

int	ft_calculate_line_height(double perp_wall_dist, int win_height)
{
	int	line_height;

	line_height = (int)(win_height / perp_wall_dist);
	return (line_height);
}

int	ft_calculate_draw_start(int line_height, int win_height)
{
	int	draw_start;

	draw_start = -line_height / 2 + win_height / 2;
	if (draw_start < 0)
		draw_start = 0;
	return (draw_start);
}

int	ft_calculate_draw_end(int line_height, int win_height)
{
	int	draw_end;

	draw_end = line_height / 2 + win_height / 2;
	if (draw_end >= win_height)
		draw_end = win_height - 1;
	return (draw_end);
}

void	ft_ray_casting(t_data *store, t_ray *ray, int x)
{
	ft_initialisation_ray(ray, store->player, x, store->win_width);
	ft_calculate_step_and_side_dist(ray, store->player);
	ft_perform_digital_differential_analysis(ray, store->map);
	ft_calculate_perpendicular_wall_distance(ray, store->player);
	ray->line_height = ft_calculate_line_height(ray->perp_wall_dist,
			store->win_height);
	ray->draw_start = ft_calculate_draw_start(ray->line_height,
			store->win_height);
	ray->draw_end = ft_calculate_draw_end(ray->line_height, store->win_height);
}
