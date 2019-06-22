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
	int			i;

	filler = ft_memalloc(sizeof(t_filler));
	filler->fd = 0;//open("/Users/ojessi/Desktop/Filler/one_map", O_RDONLY);
	filler->player = 0;
	i = 4;
	while (i-- && get_next_line(filler->fd, &line) > 0)
	{
		if (line && (int)ft_strlen(line) > 10 && !ft_strncmp(line,
				"$$$ exec p", 9))
			if (line[10] == '2' && ft_strstr(line, "ojessi.filler]"))
				filler->player = 1;
		free(line);
	}
	ft_read_param(filler);
	ft_heapmap(filler);
	ft_place_figure(filler);
	return (0);
}
