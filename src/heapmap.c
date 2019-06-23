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
				else if (x >= filler->map_x || y < 0 ||
				y >= filler->map_y)
					break ;
				else if (filler->map[y][x] == (filler->player ? 0 : -1))
					return (ves);
			}
		}
		ves++;
	}
}

void			ft_heapmap(t_filler *filler)
{
	int		i;
	int		j;

	i = -1;
	while (++i < filler->map_y)
	{
		j = -1;
		while (++j < filler->map_x)
			if (filler->map[i][j] != 0 && filler->map[i][j] != -1)
				filler->map[i][j] = ft_algor(i, j, filler);
	}
}
