/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 13:54:04 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/29 19:44:56 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizator.h"

void	ft_init_image(t_params *p)
{
	if (p->image->img_ptr)
	{
		mlx_destroy_image(p->mlx_ptr, p->image->img_ptr);
		p->image->img_ptr = NULL;
	}
	if (!p->image->img_ptr)
		p->image->img_ptr = mlx_new_image(p->mlx_ptr, WIDTH, HEIGHT);
	p->image->img_data = mlx_get_data_addr(p->image->img_ptr, &p->image->bpp,
			&p->image->size_line, &p->image->endian);
}

void	ft_create_left_image(t_params *p, t_fig *cur)
{
	int		i;
	int		j;

	i = -1;
	while (++i < cur->fig_y)
	{
		j = -1;
		while (++j < cur->fig_x)
			if (cur->fig[i][j] == '*' && (cur->sim_y != i || cur->sim_x != j))
				p->map->map[cur->y + i][cur->x + j] = '.';
	}
	if (cur->player == 0)
		p->player1.score = cur->score;
	else
		p->player2.score = cur->score;
}

int		ft_check(t_params *p, t_fig *cur)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	i = -1;
	while (++i < cur->fig_y)
	{
		j = -1;
		while (++j < cur->fig_x)
			if (cur->fig[i][j] == '*')
				if (p->map->map[cur->y + i][cur->x + j] ==
				(cur->player ? 'X' : 'O'))
					count++;
	}
	return (count);
}

void	ft_create_right_image(t_params *p, t_fig *cur)
{
	int		i;
	int		j;

	if (ft_check(p, cur) != 1)
		return ;
	i = -1;
	while (++i < cur->fig_y)
	{
		j = -1;
		while (++j < cur->fig_x)
			if (cur->fig[i][j] == '*')
			{
				if (cur->player == 0 && (p->map->map[cur->y + i][cur->x + j]
				== 'O' || p->map->map[cur->y + i][cur->x + j] == '.'))
					ft_player_o(p, cur, i, j);
				else if (cur->player == -1 && (p->map->map[cur->y + i][cur->x +
				j] == 'X' || p->map->map[cur->y + i][cur->x + j] == '.'))
					ft_player_1(p, cur, i, j);
			}
	}
}

int		ft_draw(t_params *p)
{
	static	t_fig	*cur = NULL;

	if (!cur)
		cur = *p->fig;
	!p->mlx_ptr ? p->mlx_ptr = mlx_init() : 0;
	!p->win_ptr ? p->win_ptr = mlx_new_window(p->mlx_ptr, WIDTH, HEIGHT,
			"Filler") : 0;
	p->slow ? usleep(100000) : 0;
	ft_init_image(p);
	if (p->pause && p->right)
	{
		cur ? ft_create_right_image(p, cur) : 0;
		cur = ft_move_right(cur, 1);
	}
	else if (p->pause && p->left)
	{
		cur = ft_move_left(cur, 1);
		cur ? ft_create_left_image(p, cur) : 0;
	}
	ft_print(p, cur);
	return (0);
}
