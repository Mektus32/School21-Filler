/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smth.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 18:39:28 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/27 18:39:29 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizator.h"

void	ft_calc_score(t_params *p)
{
	int 	i;
	int 	j;

	p->player1.score = 0;
	p->player2.score = 0;
	i = -1;
	while (++i < p->map->map_y)
	{
		j = -1;
		while (++j < p->map->map_x)
			if (p->map->map[i][j] == 'O' || p->map->map[i][j] == 'o')
				p->player1.score += 1;
			else if (p->map->map[i][j] == 'X' || p->map->map[i][j] == 'x')
				p->player2.score += 1;
	}
}
