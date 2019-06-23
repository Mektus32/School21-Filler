/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 17:30:10 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/23 17:30:11 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int 	small_check(t_filler *filler, int i, int j, int *count)
{
	if (i < filler->map_y && j < filler->map_x)
	{
		if (filler->map[i][j] == (!filler->player ? 0 : -1))
			(*count)++;
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

int 	check_placement(t_filler *filler, int i, int j)
{
	int i_fig;
	int j_fig;
	int count;

	i_fig = -1;
	count = 0;
	while (++i_fig < filler->fig_y)
	{
		j_fig = -1;
		while (++j_fig < filler->fig_x)
			if (filler->fig[i_fig][j_fig] == '*')
				if (small_check(filler, i_fig + i, j_fig + j, &count) == 0)
					return (0);
	}
	return (count);
}

int 	check_heat(t_filler *filler, int i, int j)
{
	int i_fig;
	int j_fig;
	int total;

	i_fig = -1;
	total = 0;
	while (++i_fig < filler->fig_y)
	{
		j_fig = -1;
		while (++j_fig < filler->fig_x)
			if (filler->fig[i_fig][j_fig] == '*')
				total += filler->map[i_fig + i][j_fig + j];
	}
	return (total);
}

void	simple_placing(t_filler *filler, t_point *answer)
{
	int 	min_sum;
	int 	tmp;
	int 	i;
	int 	j;

	i = -1;
	min_sum = 1000000;
	ft_heapmap(filler);
	while (filler->map[++i])
	{
		j = -1;
		while (filler->map[i][++j])
			if (check_placement(filler, i, j) == 1)
			{
				tmp = check_heat(filler, i, j);
				if (min_sum > tmp)
				{
					min_sum = tmp;
					answer->y = i;
					answer->x = j;
				}
			}
	}
}

void	ft_place_fig(t_filler *filler)
{
	t_point	*answer;

	answer = ft_memalloc(sizeof(t_point));
	answer->y = 0;
	answer->x = 0;
	simple_placing(filler, answer);
	ft_printf("%d %d\n", answer->y, answer->x);
	free(answer);
}
