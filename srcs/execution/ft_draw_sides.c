/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sides.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <abergman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:38:15 by abergman          #+#    #+#             */
/*   Updated: 2025/02/14 22:09:02 by abergman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

/* Функция `ft_draw_sides` отвечает за определение цвета пикселя текстуры,
	который будет отрисован на экране, в зависимости от стороны стены,
	с которой пересекся луч.Она принимает указатель на структуру `t_data`,
	содержащую все данные игры,
	и возвращает значение цвета пикселя в формате `unsigned int`.

	Первым шагом функция объявляет переменную `bin_color`,
	которая будет использоваться для хранения цвета пикселя.Изначально эта переменная устанавливается в 0.

	Далее функция проверяет значение `side` в структуре `ray`,
	чтобы определить, с какой стороны стены пересекся луч.Если `side` равно 0,
		это означает, что луч пересек северную стену,
		и цвет пикселя берется из текстуры,
	хранящейся в `store->north->address`.Координаты пикселя в текстуре рассчитываются как `HEIGHT_TEXTURE
		* store->draw->texy +
	store->draw->texx`.

	Если `side` равно 1,
	это означает, что луч пересек восточную стену,
		и цвет пикселя берется из текстуры,
	хранящейся в `store->east->address`.Координаты пикселя рассчитываются аналогичным образом.

	Если `side` равно 2,
	это означает, что луч пересек южную стену,
		и цвет пикселя берется из текстуры,
	хранящейся в `store->south->address`.

	Если `side` равно 3,
	это означает, что луч пересек западную стену,
		и цвет пикселя берется из текстуры,
	хранящейся в `store->west->address`.

	После определения цвета пикселя функция возвращает значение `bin_color`,
	которое будет использовано для отрисовки текстуры на экране.Таким образом,
		функция `ft_draw_sides` обеспечивает корректное отображение текстур в зависимости от стороны стены,
		с которой пересекся луч.
 */

unsigned int	ft_get_tetxure_color(t_data *store)
{
	unsigned int bin_color;

	bin_color = 0;
	if (store->ray->side == 0)
		bin_color = ((unsigned int *)(store->north->address))[store->north->height
			* store->draw->texy + store->draw->texx];
	else if (store->ray->side == 1)
		bin_color = ((unsigned int *)(store->east->address))[store->east->height
			* store->draw->texy + store->draw->texx];
	else if (store->ray->side == 2)
		bin_color = ((unsigned int *)(store->south->address))[store->south->height
			* store->draw->texy + store->draw->texx];
	else if (store->ray->side == 3)
		bin_color = ((unsigned int *)(store->west->address))[store->west->height
			* store->draw->texy + store->draw->texx];
	return (bin_color);
}
