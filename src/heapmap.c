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
#define EN (filler->player ? 0 : -1)

int		ft_ves(t_filler *filler, t_point tmp, int **mapint, int ves)
{
	int		in;
	int		jn;
	int		jk;

	while (++ves)
	{
		in = ft_max(0, tmp.y - ves);
		jn = ft_max(0, tmp.x - ves) - 1;
		jk = ft_min(filler->map_y - 1, tmp.x + ves);
		while (++jn <= jk)
			if (mapint[jn][in] == EN ||
			mapint[jn][ft_min(filler->map_x - 1, tmp.y + ves)] == EN)
				return (ves);
		jn = ft_max(0, tmp.x - ves);
		in--;
		while (++in <= ft_min(filler->map_x - 1, tmp.y + ves))
			if (mapint[jn][in] == EN || mapint[jk][in] == EN)
				return (ves);
	}
	return (ves);
}

int		**ft_heapmap(t_filler *filler, int **mapint)
{
	int		i;
	int		j;
	t_point	tmp;

	i = -1;
	while (++i < filler->map_y)
	{
		j = -1;
		while (++j < filler->map_x)
			if (mapint[i][j] != 0 && mapint[i][j] != -1)
			{
				tmp.y = j;
				tmp.x = i;
				mapint[i][j] = ft_ves(filler, tmp, mapint, 0);
			}
	}
	return (mapint);
}
