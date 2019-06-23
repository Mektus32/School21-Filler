/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 10:14:58 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/16 10:35:33 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void	ft_init_filler(t_filler *filler)
{
	filler->map->size_x = 0;
	filler->map->size_y = 0;
	filler->map->map = NULL;
	filler->fig->size_x = 0;
	filler->fig->size_y = 0;
	filler->fig->fig = NULL;
	filler->flag = 0;
}

int		main(void)
{
	t_filler	*filler;
	char		*line;

	filler = ft_memalloc(sizeof(t_filler));
	filler->map = ft_memalloc(sizeof(t_map));
	filler->fig = ft_memalloc(sizeof(t_fig));
	filler->player = 0;
	filler->fd = 0;open("/Users/ojessi/Desktop/Filler/one_map",  O_RDWR | O_APPEND);
	ft_init_filler(filler);
	while (get_next_line(filler->fd, &line) > 0)
	{
		//write(3, line, ft_strlen(line));
		//write(3, "\n", 1);
		ft_read_param(filler, line);
		ft_strdel(&line);
		//write(3, "check\n", 6);
//		if (filler->flag)
//			break ;
	}
	ft_strdel(&line);
	ft_frtwarr((void**)filler->map->map, filler->map->size_y);
	free(filler->map);
	free(filler);
	return (0);
}
