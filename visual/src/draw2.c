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
			arr[i * WIDTH + j] = 0x2F2A47;
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
	const int 	dy = 480 / p->map->map_y - 1;
	const int 	dx = 1050 / p->map->map_x - 1;
	int 		i;
	int 		j;
	int 		*arr;

	arr = (int*)p->image->img_data;
	i = *y - 1;
	while (++i <= dy + *y)
	{
		j = *x - 1;
		while (++j <= dx + *x)
		{
			if (i == *y || i == dy + *y || j == *x || j == dx + *x)
				arr[i * WIDTH + j] = 0x000000;
			else
				arr[i * WIDTH + j] = color;
		}
	}
	*x = j;
	if (*x >= (dx + 1) * p->map->map_x + 10)
	{
		*x = 10;
		*y = i;
		*y >= (dy + 1) * p->map->map_y + 10 ? *y = 10 : 0;
	}
}

void	ft_draw_box(t_params *p, int color)
{
	static int			i = 10;
	static int			j = 10;

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
				ft_draw_box(p, 0x170F6B);
	}
}

void	ft_draw_fig(t_params *p, t_fig *cur)
{
	const char	*name = cur->player ? p->player2.name : p->player1.name;
	const int 	color = cur->player ? p->player2.color : p->player1.color;
	const char	*y = ft_free_strjoin_duo(ft_strdup("Y -> "), ft_itoa(cur->y));
	const char	*x = ft_free_strjoin_duo(ft_strdup("X -> "), ft_itoa(cur->x));
	int 		i;

	!p->pause ? mlx_string_put(p->mlx_ptr, p->win_ptr, WIDTH / 2 - 100, HEIGHT / 2 - 100, 0xFFFFF, "PAUSE") : 0;
	mlx_string_put(p->mlx_ptr, p->win_ptr, p->map->map_y > 70 ? 1000 : 1070, 10, color, (char*)name);
	mlx_string_put(p->mlx_ptr, p->win_ptr, p->map->map_y > 70 ? 1000 : 1070, 40, color, (char*)y);
	mlx_string_put(p->mlx_ptr, p->win_ptr, p->map->map_y > 70 ? 1000 : 1070, 70, color, (char*)x);
	i = -1;
	while (++i < cur->fig_y)
		mlx_string_put(p->mlx_ptr, p->win_ptr, p->map->map_y > 70 ? 1000 : 1070, 100 + i * 15, color, cur->fig[i]);
	free((void*)y);
	free((void*)x);
}

void	ft_print(t_params *p, t_fig *cur)
{
	int 	*arr;

	arr = (int*)p->image->img_data;
	arr = ft_background(arr);
	arr = ft_draw_rectangle(10, HEIGHT - 80, p, 1);
	ft_draw_rectangle(WIDTH - 700, HEIGHT - 80, p, 2);
	ft_draw_map(p);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->image->img_ptr, 0, 0);
	ft_draw_fig(p, cur);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 10, HEIGHT - 100, p->player1.color, p->player1.name);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 10 + 100, HEIGHT - 100, p->player1.color, ft_itoa(p->player1.score));
	mlx_string_put(p->mlx_ptr, p->win_ptr, WIDTH - 700, HEIGHT - 100, p->player2.color, p->player2.name);
	mlx_string_put(p->mlx_ptr, p->win_ptr, WIDTH - 700 + 100, HEIGHT - 100, p->player2.color, ft_itoa(p->player2.score));

}