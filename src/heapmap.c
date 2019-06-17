/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 20:26:50 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/17 20:26:52 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	int		ft_algor(int i, int j, t_filler *filler)
{
	int x;
	int y;
	int ves;

	ves = 1;
	while (1)
	{
		y = i - ves - 1;
		while (++y <= i + ves)
		{
			x = j - ves - 1;
			while (++x <= j + ves)
			{
				if (x < 0)
					continue ;
				else if (x >= filler->map->size_x || y < 0 ||
				        y >= filler->map->size_y)
					break ;
				else if (filler->map->map[y][x] == (filler->player ? 'O' : 'X')
				|| filler->map->map[y][x] == (filler->player ? 'o' : 'x'))
					return (ves);
			}
		}
		ves++;
	}
}

void			ft_heapmap(t_filler *filler)
{
	int 	i;
	int 	j;

	i = -1;
	while (++i < filler->map->size_y)
	{
		j = -1;
		while (++j < filler->map->size_x)
			if (filler->map->map[i][j] != 'O' && filler->map->map[i][j] != 'X')
				filler->map->map[i][j] = '0' + ft_algor(i, j, filler);
	}

	for (int i = 0; i < filler->map->size_y; i++)
	{
		for (int j = 0; j < filler->map->size_x; j++)
			ft_printf(" %2d", filler->map->map[i][j] - '0');
		ft_printf("\n");
	}
}
