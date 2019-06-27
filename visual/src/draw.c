/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 11:44:52 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/27 11:44:53 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizator.h"

void	ft_draw_bg(t_params *p)
{
	int 	*arr;

	p->image->size_line = WIDTHW * 4;
	p->image->endian = 0;
	p->image->img_ptr = mlx_new_image(p->mlx_ptr, WIDTHW, HEIGHTW);
	p->image->img_data = mlx_get_data_addr(p->image->img_ptr, &p->image->bpp, &p->image->size_line, &p->image->endian);
	arr = (int*)p->image->img_data;
	for (int i = 0; i < 600; i++)
		for (int j = 0; j < 1200; j++)
				arr[i * WIDTHW + j] = 0x332E4D;
}

void	ft_draw_rectangle(int x, int y,t_params *p, int	num)
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
				arr[i * WIDTHW + j] = num == 1 ? p->player1.color : p->player2.color;
			else
				arr[i * WIDTHW + j] = num == 1 ? p->player1.bgcolor : p->player2.bgcolor;
		}
	}

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
			if (p->map->map[i][j] == 'X' || p->map->map[i][j] == 'x')
				ft_draw_box(p, p->player2.color);
			else if (p->map->map[i][j] == 'O' || p->map->map[i][j] == 'o')
				ft_draw_box(p, p->player1.color);
			else if (p->map->map[i][j] == '.')
				ft_draw_box(p, 0x9C8686);
	}

}

void	ft_draw_players(t_params *p)
{
	static	int i;
	ft_calc_score(p);
	ft_draw_rectangle(100, HEIGHTW - 80, p, 1);
	ft_draw_rectangle(WIDTHW - 600, HEIGHTW - 80, p, 2);
	//printf("i before = %d\n", i);
	ft_draw_map(p);
	i++;
	//printf("i after = %d", i);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->image->img_ptr, 0, 0);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 100, HEIGHTW - 100, p->player1.color, p->player1.name);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 100 + 100, HEIGHTW - 100, p->player1.color, ft_itoa(p->player1.score));
	mlx_string_put(p->mlx_ptr, p->win_ptr, WIDTHW - 600, HEIGHTW - 100, p->player2.color, p->player2.name);
	mlx_string_put(p->mlx_ptr, p->win_ptr, WIDTHW - 600 + 100, HEIGHTW - 100, p->player2.color, ft_itoa(p->player2.score));
	mlx_destroy_image(p->mlx_ptr, p->image->img_ptr);
}

void	ft_draw(t_params *p)
{
	ft_draw_bg(p);
	ft_draw_players(p);
//	ft_draw_winner(p);
}
