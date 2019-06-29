/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 16:11:17 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/29 16:11:20 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizator.h"

void	ft_player_o(t_params *p, t_fig *cur, int i, int j)
{
	if (p->map->map[cur->y + i][cur->x + j] == 'O')
	{
		cur->sim_y = i;
		cur->sim_x = j;
	}
	p->map->map[cur->y + i][cur->x + j] = 'O';
	p->player1.score = cur->score;
}

void	ft_player_1(t_params *p, t_fig *cur, int i, int j)
{
	if (p->map->map[cur->y + i][cur->x + j] == 'X')
	{
		cur->sim_y = i;
		cur->sim_x = j;
	}
	p->map->map[cur->y + i][cur->x + j] = 'X';
	p->player2.score = cur->score;
}

void	ft_draw_fig(t_params *p, t_fig *cur)
{
	const char	*name = cur->player ? p->player2.name : p->player1.name;
	const int	color = cur->player ? p->player2.color : p->player1.color;
	const char	*y = ft_free_strjoin_duo(ft_strdup("Y -> "), ft_itoa(cur->y));
	const char	*x = ft_free_strjoin_duo(ft_strdup("X -> "), ft_itoa(cur->x));
	int			i;

	!p->pause ? mlx_string_put(p->mlx_ptr, p->win_ptr, WIDTH / 2 - 100, HEIGHT
	/ 2 - 100, 0xA106E0, "PAUSE") : 0;
	mlx_string_put(p->mlx_ptr, p->win_ptr, p->map->map_y > 70 ? 1000 : 1070, 10,
			color, (char*)name);
	mlx_string_put(p->mlx_ptr, p->win_ptr, p->map->map_y > 70 ? 1000 : 1070, 40,
			color, (char*)y);
	mlx_string_put(p->mlx_ptr, p->win_ptr, p->map->map_y > 70 ? 1000 : 1070, 70,
			color, (char*)x);
	i = -1;
	while (++i < cur->fig_y)
		mlx_string_put(p->mlx_ptr, p->win_ptr, p->map->map_y > 70 ? 1000 : 1070,
				100 + i * 15, color, cur->fig[i]);
	free((void*)y);
	free((void*)x);
}

int		*ft_background(int *arr)
{
	int		i;
	int		j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			arr[i * WIDTH + j] = 0x0A071C;
	}
	return (arr);
}
