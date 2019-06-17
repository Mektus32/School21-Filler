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
				if (filler->fig->fig[imap + i - IPOINT][jmap + j - JPOINT] ==
				'x' || filler->fig->fig[imap + i - IPOINT][jmap + j - JPOINT]
				== 'X' ||
				filler->fig->fig[imap + i - IPOINT][jmap + j - JPOINT] == 'O'
				|| filler->fig->fig[imap + i - IPOINT][jmap + j - JPOINT] ==
				'o')
					return ;
			}
			else
				sum += filler->fig->fig[imap + i - IPOINT][jmap + j - JPOINT]
						- '0';
	}
	ft_printf("\n");
	//ft_printf("sum = %d filler->sum = %d\n", sum, filler->fig->sum);
	if (sum < filler->fig->sum)
	{
		ft_printf("ipoint = %2d, jpoint = %2d\n", IPOINT, JPOINT);
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
				filler->fig->y_point = i;
				filler->fig->x_point = j;
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
			if (filler->map->map[i][j] == (!filler->player ? 'O' : 'X') ||
			filler->map->map[i][j] == (!filler->player  ? 'o' : 'x'))
				ft_find_contact(filler, i, j);
	}
}
