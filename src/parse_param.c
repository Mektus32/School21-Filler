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

static	void	ft_create_fig(t_filler *filler, char *line)
{
	static int 	i;
	int 		j;

	j = -1;
	while (line[++j] != '\0' && j < filler->fig->size_x)
		filler->fig->fig[i][j] = line[j];
	i++;
	if (i == filler->fig->size_y)
	{
		ft_heapmap(filler);
		ft_place_figure(filler);
	}
}

static	void	ft_init_fig(t_filler *filler, char *line)
{
	int		i;

	i = 0;
	while (ft_isdigit(line[i]) == 0)
		++i;
	filler->fig->size_y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]) == 1)
		++i;
	++i;
	filler->fig->size_x = ft_atoi(&line[i]);
	filler->fig->fig = ft_memalloc(sizeof(char*) * filler->fig->size_y);
	i = -1;
	while (++i < filler->fig->size_y)
		filler->fig->fig[i] = ft_memalloc(sizeof(char) * filler->fig->size_x);
}

static	void	ft_create_map(t_filler *filler, char *line)
{
	static int	i = 0;
	int 		j;
	int 		check;

	j = -1;
	check = i;
	line = ft_strtolower(line);
	while (line[++j + 4] != '\0' && j < filler->map->size_x)
	{
		if (line[j + 4] == '.')
			filler->map->map[i][j] = 1;
		else if (line[j + 4] == 'o')
			filler->map->map[i][j] = 0;
		else if (line[j + 4] == 'x')
			filler->map->map[i][j] = -1;
	}
	i++;
}

static	void	ft_init_map(t_filler *filler, char *line)
{
	int		i;

	i = 0;
	while (ft_isdigit(line[i]) == 0)
		++i;
	filler->map->size_y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]) == 1)
		++i;
	++i;
	filler->map->size_x = ft_atoi(&line[i]);
	filler->map->map = ft_memalloc(sizeof(int*) * filler->map->size_y);
	i = -1;
	while (++i < filler->map->size_y)
		filler->map->map[i] = ft_memalloc(sizeof(int) * filler->map->size_x);
}

void		ft_read_param(t_filler *filler, char *line)
{
	if (!filler->player)
		if (ft_strstr(line, "p2") && ft_strstr(line, "ojessi"))
			filler->player = 1;
	if (ft_strstr(line, "Plateau") && !filler->map->size_y &&
	!filler->map->size_x)
		ft_init_map(filler, line);
	if ((line[0] == '0' || line[0] == '1') && filler->map)
		ft_create_map(filler, line);
	if (ft_strstr(line, "Piece") && !filler->fig->size_x &&
	!filler->fig->size_y)
		ft_init_fig(filler, line);
	if ((line[0] == '*' || line[0] == '.') && filler->fig)
		ft_create_fig(filler, line);
}
