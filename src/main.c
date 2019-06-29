/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 17:56:06 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/29 19:56:39 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_init_filler(t_filler *filler)
{
	filler->fd = 0;
	filler->player = 0;
	filler->map_y = 0;
	filler->map_x = 0;
	filler->fig_y = 0;
	filler->fig_x = 0;
}

int		main(void)
{
	t_filler	filler;
	char		*line;

	ft_init_filler(&filler);
	while (1)
	{
		if (get_next_line(filler.fd, &line) < 1)
			break ;
		ft_read_params(&filler, line);
		ft_strdel(&line);
	}
	if (filler.map)
		ft_frtwarr((void**)filler.map, filler.map_y);
	return (0);
}
