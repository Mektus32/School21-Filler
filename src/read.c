/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 18:00:24 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/23 18:00:25 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_define_map(t_filler *filler, char *line)
{
	int		i;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	filler->map_y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	filler->map_x = ft_atoi(&line[i]);
	filler->map = ft_memalloc(sizeof(int*) * filler->map_y);
	i = -1;
	while (++i < filler->map_y)
		filler->map[i] = ft_memalloc(sizeof(int) * filler->map_x);
}

void	ft_create_map(t_filler *filler, char *line)
{
	static	int i;
	int			j;

	j = -1;
	line = ft_strtolower(line);
	while (++j < filler->map_x)
		if (line[4 + j] == '.')
			filler->map[i][j] = 1;
		else if (line[4 + j] == 'o')
			filler->map[i][j] = 0;
		else if (line[4 + j] == 'x')
			filler->map[i][j] = -1;
	i++;
	if (i == filler->map_y)
	{
		i = 0;
		return ;
	}
}

void	ft_define_fig(t_filler *filler, char *line)
{
	int		i;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	filler->fig_y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	filler->fig_x = ft_atoi(&line[i]);
	filler->fig = ft_memalloc(sizeof(char*) * filler->fig_y);
	i = -1;
	while (++i < filler->fig_y)
	{
		filler->fig[i] = ft_memalloc(sizeof(char) * (filler->fig_x + 1));
		filler->fig[i][filler->fig_x] = '\0';
	}
}

void	ft_create_fig(t_filler *filler, char *line)
{
	static	int i;

	filler->fig[i] = ft_strcpy(filler->fig[i], line);
	i++;
	if (i == filler->fig_y)
	{
		ft_place_fig(filler);
		ft_frtwarr((void**)filler->fig, filler->fig_y);
		//ft_frtwarr((void**)filler->map, filler->map_y);
		i = 0;
	}
}

void	ft_read_params(t_filler *filler, char *line)
{
	if (ft_strstr(line, "p2") && ft_strstr(line, "ojessi"))
		filler->player = -1;
	else if (ft_strstr(line, "Plateau") && !filler->map)
		ft_define_map(filler, line);
	else if (filler->map && (line[0] == '0' || line[0] == '1'))
		ft_create_map(filler, line);
	else if (ft_strstr(line, "Piece"))
		ft_define_fig(filler, line);
	else if (filler->fig && (line[0] == '.' || line[0] == '*'))
		ft_create_fig(filler, line);
}
