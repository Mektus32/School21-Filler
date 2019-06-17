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

	filler->map->map = ft_memalloc(sizeof(char*) * filler->map->size_y);
	get_next_line(filler->fd, &line);
	free(line);
	i = -1;
	while (++i < filler->map->size_y && get_next_line(filler->fd, &line) > 0)
	{
		filler->map->map[i] = ft_strdup(line + 4);
		free(line);
	}
}

static	void	ft_read_fig(t_filler *filler)
{
	char	*line;
	int		i;

	filler->fig->fig = ft_memalloc(sizeof(char*) * filler->fig->size_y);
	i = -1;
	while (get_next_line(filler->fd, &line) > 0)
	{
		filler->fig->fig[++i] = ft_strdup(line);
		free(line);
	}
}

static	void	ft_init_map(t_filler *filler, char *line)
{
	int		i;

	filler->map = ft_memalloc(sizeof(t_filler));
	filler->map->size_y = ft_atoi(line + 8);
	i = 8;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	filler->map->size_x = ft_atoi(line + i + 1);
	ft_read_map(filler);
}

static	void	ft_init_fig(t_filler *filler, char *line)
{
	int		i;

	filler->fig = ft_memalloc(sizeof(t_fig));
	filler->fig->size_y = ft_atoi(line + 6);
	i = 6;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	filler->fig->size_x = ft_atoi(line + i + 1);
	ft_read_fig(filler);
}

void			ft_read_param(t_filler *filler)
{
	char	*line;

	while (get_next_line(filler->fd, &line) > 0)
	{
		if (!ft_strncmp(line, "Plateau", 7))
			ft_init_map(filler, line);
		else if (!ft_strncmp(line, "Piece", 5))
			ft_init_fig(filler, line);
		free(line);
	}
}
