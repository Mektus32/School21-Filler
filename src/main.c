/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 13:34:18 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/15 15:22:10 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_filler	*filler;
	char		*line;
	int			i;
	
	filler = ft_memalloc(sizeof(t_filler));
	i = 4;
	filler->fd = open("one_map", O_RDONLY);
	filler->player = 0;
	while (get_next_line(filler->fd, &line) > 0 && --i)
	{
		if ((int)ft_strlen(line) > 10 && !ft_strncmp(line, "$$$ exec p", 10))
			if (line[11] == '1' &&
			!ft_strncmp(line + 15, "ojessi.filler", 13))
			filler->player = 1;
		free(line);
	}
	ft_get_param(filler);
	for (int i = 0; i < filler->map->size_y; i++)
	{
		for (int j = 0; j < filler->map->size_x; i++)
			ft_printf("%c", filler->map->map[i][j]);
		ft_printf("\n");
	}
	ft_printf("\n");
	for (int i = 0; i < filler->fig->size_y; i++)
	{
		for (int j = 0; j < filler->fig->size_x; j++)
			ft_printf("%c", filler->fig->fig[i][j]);
		ft_printf("\n");
	}
	return (0);
}