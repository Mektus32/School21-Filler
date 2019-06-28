/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 17:02:58 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/28 17:03:00 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizator.h"

int 	*ft_background(int *arr)
{
	int 	i;
	int 	j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			arr[i * WIDTH + j] = 0x0B2F74;
	}
	return (arr);
}

int 	*ft_draw_rectangle(int x, int y, t_params *p, int num)
{
	int 			i;
	int 			j;
	int 			*arr;

	arr = (int*)p->image->img_data;
	i = y;
	while (++i < y + 10)
	{
		j = x;
		while (++j < x + 400)
		{
			if (j < (((num == 1 ? p->player1.score : p->player2.score) * 400) / (double)(p->map->map_x * p->map->map_y)) + x)
				arr[i * WIDTH + j] = num == 1 ? p->player1.color : p->player2.color;
			else
				arr[i * WIDTH + j] = num == 1 ? p->player1.bgcolor : p->player2.bgcolor;
		}
	}
	return (arr);
}

void	ft_next(t_params *p, int *y, int *x, int color)
{
	const int 	dy = 400 / p->map->map_y - 1;
	const int 	dx = 950 / p->map->map_x - 1;
	int 		i;
	int			j;
	int 		*arr;

	arr = (int*)p->image->img_data;
	i = -1;
	while (++i < dy)
	{
		arr[(*y + i) * WIDTH + *x + 1] = 0xFFFFFF;
		j = 0;
		if (i != 0)
			while (++j < dx)
				arr[(*y + i + 1) * WIDTH + *x + j] = color;
		if (i == 0)
			while (++j < dx)
				arr[(*y + i) * WIDTH + *x + 1 + j] = 0xFFFFFF;
		arr[(*y + i) * WIDTH + *x + 1 + j] = 0xFFFFFF;
	}
	i = -1;
	while (++i < 1)
	{
		j = 0;
		while (++j < dx + 1)
			arr[(*y + dy + i) * WIDTH + *x + j] = 0xFFFFFF;
	}
	*x += dx + 1;
	if (*x > 1000)
	{
		*x = 100;
		*y += dy + 1;
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

void	ft_draw_map(t_params *p)
{
	int 	i;
	int 	j;

	i = -1;
	while (++i < p->map->map_y)
	{
		j = -1;
		while (++j < p->map->map_x)
			if (p->map->map[i][j] == 'X')
				ft_draw_box(p, p->player2.color);
			else if (p->map->map[i][j] == 'O')
				ft_draw_box(p, p->player1.color);
			else if (p->map->map[i][j] == '.')
				ft_draw_box(p, 0x9C8686);
	}
}

void	ft_print(t_params *p, t_fig *cur)
{
	int 	*arr;

	arr = (int*)p->image->img_data;
	arr = ft_background(arr);
	arr = ft_draw_rectangle(100, HEIGHT - 80, p, 1);
	ft_draw_rectangle(WIDTH - 600, HEIGHT - 80, p, 2);
	ft_draw_map(p);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->image->img_ptr, 0, 0);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 100, HEIGHT - 100, p->player1.color, p->player1.name);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 100 + 100, HEIGHT - 100, p->player1.color, ft_itoa(p->player1.score));
	mlx_string_put(p->mlx_ptr, p->win_ptr, WIDTH - 600, HEIGHT - 100, p->player2.color, p->player2.name);
	mlx_string_put(p->mlx_ptr, p->win_ptr, WIDTH - 600 + 100, HEIGHT - 100, p->player2.color, ft_itoa(p->player2.score));

}