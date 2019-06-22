/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paste_fig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 21:54:47 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/17 21:54:49 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define IPOINT filler->fig->y_point
#define JPOINT filler->fig->x_point

static	void	ft_valid_place(t_filler *filler, int imap, int jmap)
{
	int 	i;
	int 	j;
	int 	sum;

	if (imap - IPOINT < 0 || imap + (filler->fig->size_y - IPOINT)
	> filler->map->size_y || jmap - JPOINT < 0 || jmap +
	(filler->fig->size_x - JPOINT) > filler->map->size_x)
		return ;
	sum = 0;
	i = -1;
	while (++i < filler->fig->size_y)
	{
		j = -1;
		while (++j < filler->fig->size_x)
			if (filler->fig->fig[i][j] == '*' && (IPOINT != i || JPOINT != j))
			{
				if (filler->map->map[imap + i - IPOINT][jmap + j - JPOINT] == -1
				|| filler->map->map[imap + i - IPOINT][jmap + j - JPOINT] == 0)
					return ;
				else
					sum += filler->map->map[imap + i - IPOINT][jmap + j - JPOINT];
			}
	}
	if (sum < filler->fig->sum)
	{
		filler->fig->sum = sum;
		filler->map->y_map = imap;
		filler->map->x_map = jmap;
	}
}

static	void	ft_find_contact(t_filler *filler, int imap, int jmap)
{
	int 	i;
	int 	j;

	i = -1;
	while (++i < filler->fig->size_y)
	{
		j = -1;
		while (++j < filler->fig->size_x)
			if (filler->fig->fig[i][j] == '*')
			{
				IPOINT = i;
				JPOINT = j;
				ft_valid_place(filler, imap, jmap);
			}
	}
}

void			ft_place_figure(t_filler *filler)
{
	int 	i;
	int 	j;

	filler->fig->sum = 10000000;
	i = -1;
	while (++i < filler->map->size_y)
	{
		j = -1;
		while (++j < filler->map->size_x)
			if (filler->map->map[i][j] == (!filler->player ? 0 : -1))
				ft_find_contact(filler, i, j);
	}
	//ft_printf("%d %d\n", filler->map->y_map - IPOINT, filler->map->x_map - JPOINT);
	printf("%d %d\n", 12, 14);
	exit (0);
}
