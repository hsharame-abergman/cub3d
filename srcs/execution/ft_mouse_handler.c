/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:56:23 by abergman          #+#    #+#             */
/*   Updated: 2025/02/14 00:06:49 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

/* Первым шагом функция сохраняет текущие значения направления игрока по оси X(`dir_x`)
и вектора камеры по оси X(`vector_x`) в переменные `old_dir_x` и `old_vector_x` соответственно.
Это необходимо для последующих вычислений новых значений направлений.

	Далее функция обновляет направление игрока по оси X и Y,
	используя тригонометрические функции косинуса и синуса с отрицательной скоростью поворота
	(`- ROTATE_SPEED`).Новое значение направления по оси X рассчитывается как комбинация старого
		значения направления по оси X и текущего значения направления по оси Y,
		умноженных на соответствующие тригонометрические функции.Аналогично,
	новое значение направления по оси Y рассчитывается как комбинация старого значения направления
	по оси X и текущего значения направления по оси Y
		.

	Затем функция обновляет вектор камеры по осям X и Y аналогичным образом.Новое значение вектора
	по оси X рассчитывается как комбинация старого значения вектора по оси X и текущего значения вектора по оси Y,
	умноженных на соответствующие тригонометрические функции.Новое значение вектора по оси Y рассчитывается
		как комбинация старого значения вектора по оси X и текущего значения вектора по оси Y.

	Таким образом,
	функция `ft_move_right` корректно поворачивает игрока вправо,
	обновляя его направление и вектор камеры в зависимости от заданной скорости поворота.
 */

void	ft_move_right(t_data *store)
{
	double	old_dir_x;
	double	old_vector_x;

	old_dir_x = store->player->dir_x;
	old_vector_x = store->player->vector_x;
	store->player->dir_x = store->player->dir_x * cos(-ROTATE_SPEED)
		- store->player->dir_y * sin(-ROTATE_SPEED);
	store->player->dir_y = old_dir_x * sin(-ROTATE_SPEED) + store->player->dir_y
		* cos(-ROTATE_SPEED);
	store->player->vector_x = store->player->vector_x * cos(-ROTATE_SPEED)
		- store->player->vector_y * sin(-ROTATE_SPEED);
	store->player->vector_y = old_vector_x * sin(-ROTATE_SPEED)
		+ store->player->vector_y * cos(-ROTATE_SPEED);
}

void	ft_move_left(t_data *store)
{
	double	old_dir_x;
	double	old_vector_x;

	old_dir_x = store->player->dir_x;
	old_vector_x = store->player->vector_x;
	store->player->dir_x = store->player->dir_x * cos(ROTATE_SPEED)
		- store->player->dir_y * sin(ROTATE_SPEED);
	store->player->dir_y = old_dir_x * sin(ROTATE_SPEED) + store->player->dir_y
		* cos(ROTATE_SPEED);
	store->player->vector_x = store->player->vector_x * cos(ROTATE_SPEED)
		- store->player->vector_y * sin(ROTATE_SPEED);
	store->player->vector_y = old_vector_x * sin(ROTATE_SPEED)
		+ store->player->vector_y * cos(ROTATE_SPEED);
}

int	ft_mouse_handler(int x, int y, t_data *store)
{
	(void)y;
	if (x > store->player->mouse_x && x <= WIDTH)
	{
		ft_move_left(store);
	}
	else if (x < store->player->mouse_x && x >= 0)
	{
		ft_move_right(store);
	}
	store->player->mouse_x = x;
	return (1);
}
