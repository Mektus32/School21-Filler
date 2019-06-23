/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 18:24:54 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/23 18:24:56 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_min_sum(t_filler *filler, int imap, int jmap)
{
	int		i;
	int		j;
	int		sum;

	i = -1;
	sum = 0;
	while (++i < filler->fig_y)
	{
		j = -1;
		while (++j < filler->fig_x)
			if (filler->fig[i][j] == '*' && filler->map[i + imap][j + jmap] != 0
			&& filler->map[i + imap][j + jmap] != -1)
				sum += filler->map[i + imap][j + jmap];
	}
	return (sum);
}

int		ft_check_place(t_filler *filler, int imap, int jmap)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	i = -1;
	while (++i < filler->fig_y)
	{
		j = -1;
		while (++j < filler->fig_x)
			if (filler->fig[i][j] == '*')
				if ((filler->fig_y + imap < filler->map_y) && (filler->fig_x +
				jmap < filler->map_x))
					if (filler->map[i + imap][j + jmap] == 0 ||
					filler->map[i + imap][j + jmap] == -1)
					{
						if (filler->player ==
						filler->map[i + imap][j + jmap])
							count++;
						else
							return (0);
					}
	}
	return (count);
}

void	ft_place_fig(t_filler *filler)
{
	t_point *answer;
	int		i;
	int		j;
	int		tmp;
	int		min_sum;

	answer = ft_memalloc(sizeof(t_point));
	min_sum = 1000000;
	ft_heapmap(filler);
	answer->x = 0;
	answer->y = 0;
	//ft_init_ans(answer, &min_sum, filler);
	i = -1;
	while (++i < filler->map_y)
	{
		j = -1;
		while (++j < filler->map_x)
			if (ft_check_place(filler, i, j) == 1)
			{
				tmp = ft_min_sum(filler, i, j);
				if (tmp < min_sum)
				{
					min_sum = tmp;
					answer->y = i;
					answer->x = j;
				}
			}
	}
	ft_printf("%d %d\n", answer->y, answer->x);
	free(answer);
}
