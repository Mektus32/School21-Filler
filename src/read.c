/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 14:25:30 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/23 14:25:31 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void	define_map(t_filler *filler, char *line)
{
	int		i;

	i = 0;
	while (ft_isdigit(line[i]) == 0)
		++i;
	filler->map_y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]) == 1)
		++i;
	++i;
	filler->map_x = ft_atoi(&line[i]);
	filler->map = ft_memalloc(sizeof(int*) * filler->map_y);
	i = -1;
	while (++i < filler->map_y)
		filler->map[i] = ft_memalloc(sizeof(int) * filler->map_x);
}

static void		create_map(t_filler *filler, char *line)
{
	static	int 	i;
	int 			j;

	j = -1;
	line = ft_strtolower(line);
	while (++j < filler->map_x && line[4 + j] != '\0')
		if (line[4 + j] == '.')
			filler->map[i][j] = 1;
		else if (line[4 + j] == 'o')
			filler->map[i][j] = 0;
		else if (line[4 + j] == 'x')
			filler->map[i][j] = -1;
	i++;
}

static	void	define_fig(t_filler *filler, char *line)
{
	int		i;

	i = 0;
	while (ft_isdigit(line[i]) == 0)
		++i;
	filler->fig_y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]) == 1)
		++i;
	++i;
	filler->fig_x = ft_atoi(&line[i]);
	filler->fig = ft_memalloc(sizeof(char*) * filler->fig_y);
	i = -1;
	while (++i < filler->fig_y)
		filler->fig[i] = ft_memalloc(sizeof(char) * filler->fig_x);
}

void			ft_read(t_filler *filler, char *line, int *index)
{
	if (!filler->player)
		if (ft_strstr(line, "p2") && ft_strstr(line, "ojessi"))
			filler->player = 1;
	if (!filler->map_y && !filler->map_x && ft_strstr(line, "Plateau"))
		define_map(filler, line);
	if ((line[0] == '0' || line[0] == '1') && filler->map)
		create_map(filler, line);
	if (ft_strstr(line, "Piece"))
		define_fig(filler, line);
	if (filler->fig && (line[0] == '.' || line[0] == '*'))
	{
		ft_strcpy(filler->fig[(*index)++], line);
		if (*(index) == filler->fig_y)
		{
			*index = 0;
			ft_place_fig(filler);
			ft_frtwarr((void**)filler->fig, filler->fig_y);
		}
	}
}
