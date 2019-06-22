/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 19:01:43 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/17 19:01:48 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void	ft_read_map(t_filler *filler)
{
	char	*line;
	int		i;
	int 	j;

	line = NULL;
	filler->map->map = ft_memalloc(sizeof(int*) * filler->map->size_y);
	get_next_line(filler->fd, &line);
	//write(3, line, ft_strlen(line));
	//write(3, "\n", 1);
	ft_strdel((&line));
	i = -1;
	while (++i < filler->map->size_y && get_next_line(filler->fd, &line) > 0)
	{
		//write(3, line, ft_strlen(line));
		//write(3, "\n", 1);
		filler->map->map[i] = (int*)ft_memalloc(sizeof(int) *
				filler->map->size_x);
		j = -1;
		line = ft_strtolower(line);
		while (++j < filler->map->size_x)
		{
			if (line[4 + j] == 'x')
				filler->map->map[i][j] = -1;
			else if (line[4 + j] == 'o')
				filler->map->map[i][j] = 0;
			else if (line[4 + j] == '.')
				filler->map->map[i][j] = 1;
		}
		ft_strdel((&line));
	}
}

static	void	ft_read_fig(t_filler *filler)
{
	char	*line;
	int		i;

	line = NULL;
	filler->fig->fig = ft_memalloc(sizeof(char*) * filler->fig->size_y);
	i = -1;
	while (get_next_line(filler->fd, &line) > 0)
	{
		filler->fig->fig[++i] = (char*)malloc(sizeof(char) *
				filler->fig->size_x);
		filler->fig->fig[i] = ft_strcpy(filler->fig->fig[i], line);
		ft_strdel((&line));
	}
}

static	void	ft_init_map(t_filler *filler, char **line)
{
	int		i;

	filler->map = ft_memalloc(sizeof(t_map));
	filler->map->size_y = ft_atoi(*line + 8);
	i = 8;
	while ((*line)[i] >= '0' && (*line)[i] <= '9')
		i++;
	filler->map->size_x = ft_atoi(*line + i + 1);
	ft_strdel(line);
	ft_read_map(filler);
}

static	void	ft_init_fig(t_filler *filler, char **line)
{
	int		i;

	filler->fig = ft_memalloc(sizeof(t_fig));
	filler->fig->size_y = ft_atoi(*line + 6);
	i = 6;
	while ((*line)[i] >= '0' && (*line)[i] <= '9')
		i++;
	filler->fig->size_x = ft_atoi(*line + i + 1);
	ft_strdel(line);
	ft_read_fig(filler);
}

void			ft_read_param(t_filler *filler)
{
	char	*line;

	line = NULL;
	while (get_next_line(filler->fd, &line) > 0)
	{
		//write(3, line, ft_strlen(line));
		//write(3, "\n", 1);
		if (!ft_strncmp(line, "Plateau", 7))
			ft_init_map(filler, &line);
		else if (!ft_strncmp(line, "Piece", 5))
			ft_init_fig(filler, &line);
		//write(3, "check\n", 6);
	}
}
