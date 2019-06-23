/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 14:18:37 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/23 14:18:38 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int 	main(void)
{
	t_filler	filler;
	char 		*line;
	int 		index;
	int 		fd;

	index = 0;
	line = NULL;
	ft_bzero(&filler, sizeof(t_filler));
	fd = open("/Users/ojessi/Desktop/Filler/one_map", O_RDWR | O_APPEND);
	while (get_next_line(fd, &line) > 0)
	{
		//write(3, line, ft_strlen(line));
		//write(3, "\n", 1);
		ft_read(&filler, line, &index);
		ft_strdel(&line);
		//write(3, "end loop\n", ft_strlen("end loop\n"));
	}
	ft_strdel(&line);
	ft_frtwarr((void**)filler.map, filler.map_y);
	close(fd);
	return (0);
}
