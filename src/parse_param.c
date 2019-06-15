/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 13:46:57 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/15 15:25:34 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void	ft_create_map(t_filler *filler)
{
	int		i;
	char	*line;
	int		j;
	
	j = filler->map->size_y;
	filler->map->map = (char**)malloc(sizeof(char*) * filler->map->size_y);//ft_memalloc(sizeof(char*) * filler->map.size_y);
	i = -1;
	while (++i < filler->map->size_y)
		filler->map->map[i] = ft_memalloc(sizeof(char) * filler->map->size_x + 1);
	i = -1;
	while (get_next_line(filler->fd, &line) > 0 && j--)
	{
		//ft_printf("$%s\n", line);
		if (i >= 0)
			filler->map->map[i] = ft_strcpy(filler->map->map[i], line + 4);
		printf("%s\n", filler->map->map[i]);
		free(line);
	}
}

static	void	ft_create_fig(t_filler *filler)
{
	int		i;
	char	*line;
	
	filler->fig->fig = ft_memalloc(sizeof(char*) * filler->fig->size_y);
	i = -1;
	while (++i < filler->fig->size_y)
		filler->fig->fig[i] = ft_memalloc(sizeof(char) * filler->fig->size_x + 1);
	i = -1;
	while (get_next_line(filler->fd, &line) > 0 && i < filler->fig->size_y)
	{
		if (i >= 0)
			ft_strcpy(filler->fig->fig[i], line);
		free(line);
	}
}

void	ft_get_param(t_filler *filler)
{
	char	*line;
	int		i;
	
	while (get_next_line(filler->fd, &line) > 0)
	{
		if (!ft_strncmp(line, "Plateau", 7))
		{
			filler->map = ft_memalloc(sizeof(t_map));
			filler->map->size_y = ft_atoi(line + 8);
			i = 0;
			while (line[8 + i] >= '0' && line[8 + i] <= '9')
				i++;
			filler->map->size_x = ft_atoi(line + 9 + i);
			ft_create_map(filler);
		}
		else if (!ft_strncmp(line, "Piece", 5))
		{
			filler->fig = ft_memalloc(sizeof(t_map));
			filler->fig->size_y = ft_atoi(line + 6);
			i = 0;
			while (line[6 + i] >= '0' && line[6 + i] <= '9')
				i++;
			filler->fig->size_x = ft_atoi(line + 7 + i);
			ft_create_fig(filler);
		}
		free(line);
	}
}