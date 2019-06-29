/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 18:24:54 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/29 20:03:53 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		**ft_init_intmap(t_filler *filler)
{
	int		i;
	int		j;
	int		**mapint;

	mapint = ft_memalloc(sizeof(int*) * filler->map_y);
	i = -1;
	while (++i < filler->map_y)
		mapint[i] = ft_memalloc(sizeof(int) * filler->map_x);
	i = -1;
	while (++i < filler->map_y)
	{
		j = -1;
		while (++j < filler->map_x)
			if (filler->map[i][j] == 'x' && filler->player == 0)
				mapint[i][j] = -1;
			else if (filler->map[i][j] == 'o' && filler->player == -1)
				mapint[i][j] = 0;
			else
				mapint[i][j] = 1;
	}
	return (mapint);
}

int		ft_norm(t_filler *filler, int count, int sum)
{
	if (count == 1 && sum < filler->sum)
	{
		filler->sum = sum;
		return (1);
	}
	return (0);
}

int		ft_contact(t_filler *filler, int **mapint, int imap, int jmap)
{
	int		i;
	int		j;
	int		count;
	int		sum;

	sum = 0;
	count = 0;
	i = -1;
	while (++i < filler->fig_y)
	{
		j = -1;
		while (++j < filler->fig_x)
			if (filler->fig[i][j] == '*')
			{
				if (filler->map[imap + i][jmap + j] ==
				(!filler->player ? 'o' : 'x'))
					count++;
				else if (filler->map[imap + i][jmap + j] ==
				(filler->player ? 'o' : 'x') || count == 2)
					return (0);
				sum += mapint[imap + i][jmap + j];
			}
	}
	return (ft_norm(filler, count, sum));
}

void	ft_place_fig(t_filler *filler)
{
	int		**mapint;
	int		i;
	int		j;

	filler->mapcor.y = 0;
	filler->mapcor.x = 0;
	filler->sum = 100000;
	mapint = ft_init_intmap(filler);
	mapint = ft_heapmap(filler, mapint);
	i = -1;
	while (++i < filler->map_y)
	{
		j = -1;
		while (++j < filler->map_x)
			if (i + filler->fig_y <= filler->map_y && j +
			filler->fig_x <= filler->map_x)
				if (ft_contact(filler, mapint, i, j))
				{
					filler->mapcor.y = i;
					filler->mapcor.x = j;
				}
	}
	ft_frtwarr((void**)mapint, filler->map_y);
	ft_printf("%d %d\n", filler->mapcor.y, filler->mapcor.x);
}
