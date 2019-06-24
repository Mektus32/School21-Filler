/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 11:06:30 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/24 11:06:31 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_check_mask(t_filler *filler, int imap, int jmap, t_point tmpfig)
{
	int 	i;
	int 	j;
	int 	count;
	int 	sum;

	sum = 0;
	count = 0;
	i = -1;
	while (++i < filler->fig_y)
	{
		j = -1;
		while (++j < filler->fig_x)
			if (filler->fig[i][j] == '*')
			{
				if (filler->map[imap + i - tmpfig.y][jmap + j - tmpfig.x]
				== filler->player)
					count++;
				else if (filler->map[imap + i - tmpfig.y][jmap + j - tmpfig.x]
				== 0 ||
				filler->map[imap + i - tmpfig.y][jmap + j - tmpfig.x] == -1)
					return (0);
				else
					sum += filler->map[imap + i - tmpfig.y][jmap + j - tmpfig.x];
			}

	}
	if (count == 1)
		return (sum);
	return (0);
}

int 	ft_contact(t_filler *filler, int imap, int jmap)
{
	int 	i;
	int 	j;
	t_point	tmpfig;
	int 	tmp;

	i = -1;
	while (++i < filler->fig_y)
	{
		j = -1;
			while (++j < filler->fig_x)
				if (filler->fig[i][j] == '*')
				{
					if (imap - i < 0 || jmap - j < 0 || imap + (filler->fig_y - i) >= filler->map_y ||
						jmap + (filler->fig_x - j) >= filler->map_x)
						continue ;
					else
					{
						tmpfig.y = i;
						tmpfig.x = j;
						if ((tmp = ft_check_mask(filler, imap, jmap, tmpfig)) && tmp < filler->sum)
						{
							filler->mapcor.y = imap - tmpfig.y;
							filler->mapcor.x = jmap - tmpfig.x;
							filler->sum = tmp;
						}

					}
			}
	}
	return (0);
}

void	ft_place_fig(t_filler *filler)
{
	int 	i;
	int 	j;

	ft_heapmap(filler);
	filler->sum = 1000000;
	filler->mapcor.y = 0;
	filler->mapcor.x = 0;
	i = -1;
	while (++i < filler->map_y)
	{
		j = -1;
		while (++j < filler->map_x)
			if (filler->player == filler->map[i][j])
				ft_contact(filler, i, j);
	}
	ft_printf("%d %d\n", filler->mapcor.y, filler->mapcor.x);
}
