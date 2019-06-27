/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 19:13:48 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/27 19:13:49 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizator.h"

void	ft_next(t_params *p, int *y, int *x, int color)
{
	const int 	dy = 400 / p->map->map_y - 2;
	const int 	dx = 950 / p->map->map_x - 2;
	int 		i;
	int			j;
	int 		*arr;

	//printf("dy = %d dx = %d\n", dy, dx);
	//printf("y = %d x = %d\n", *y, *x);
	arr = (int*)p->image->img_data;
	i = -1;
	while (++i < dy)
	{
		j = -1;
		while (++j < dx)
			arr[(*y + i) * WIDTHW + *x + j] = color;
		arr[(*y + i) * WIDTHW + *x + 1 + j] = 0xFFFFFF;
		arr[(*y + i) * WIDTHW + *x + 2 + j] = 0xFFFFFF;
	}
	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (++j < dx + 2)
			arr[(*y + dy + i) * WIDTHW + *x + j] = 0xFFFFFF;
	}
	*x += dx + 2;
	if (*x > 1000)
	{
		*x = 100;
		*y += dy + 2;
	}
	if (*y >= 430)
	{
		*y = 50;
		*x = 100;
	}
}

void	ft_draw_box(t_params *p, int color)
{
	static int			i = 50;
	static int			j = 100;

	ft_next(p, &i, &j, color);
}
