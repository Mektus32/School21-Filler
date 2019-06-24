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

static	int		ft_algor(int i, int j, t_filler *filler, int **mapint)
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
				else if (mapint[y][x] == (filler->player ? 0 : -1))
					return (ves);
			}
		}
		ves++;
	}
}

int				**ft_heapmap(t_filler *filler, int **mapint)
{
	int		i;
	int		j;

	i = -1;
	while (++i < filler->map_y)
	{
		j = -1;
		while (++j < filler->map_x)
			if (mapint[i][j] != 0 && mapint[i][j] != -1)
				mapint[i][j] = ft_algor(i, j, filler, mapint);
	}
	return (mapint);
}
