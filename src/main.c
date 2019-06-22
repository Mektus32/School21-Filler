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

int		main(void)
{
	t_filler	*filler;
	char		*line;


	filler = ft_memalloc(sizeof(t_filler));
	filler->fd = open("/Users/ojessi/Desktop/Filler/one_map",  O_RDWR | O_APPEND);
	filler->player = 0;
	if (get_next_line(filler->fd, &line) > 0)
	{
		//write(3, line, ft_strlen(line));
		//write(3, "\n", 1);
		if (line && (int)ft_strlen(line) > 10 && !ft_strncmp(line,
				"$$$ exec p", 9))
			if (line[10] == '2' && ft_strstr(line, "ojessi.filler]"))
				filler->player = 1;
		ft_strdel(&line);
	}
	ft_read_param(filler);
	ft_heapmap(filler);
	ft_place_figure(filler);
	ft_frtwarr((void**)filler->fig->fig, filler->fig->size_y);
	ft_frtwarr((void**)filler->map->map, filler->map->size_y);
	free(filler->map);
	free(filler->fig);
	free(filler);
	return (0);
}
