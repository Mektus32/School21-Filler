/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 23:10:31 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/24 23:10:32 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizator.h"

void	ft_define_map(t_params *p, char *line)
{
	int		i;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	p->map->map_y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	p->map->map_x = ft_atoi(&line[i]);
	p->map->map = ft_memalloc(sizeof(char*) * p->map->map_y);
	i = -1;
	while (++i < p->map->map_y)
		p->map->map[i] = ft_memalloc(sizeof(char) * p->map->map_x);
}

void	ft_create_map(t_params *p, char *line)
{
	static	int i;
	j = -1;
	while (++j < p->map->map_x)
		p->map->map[i] = ft_strcpy(p->map->map[i], &line[4]);
	i++;
	if (i == p->map->map_y)
		i = 0;
}

void	ft_read_param(t_params *p)
{
	char	*line;
	if (p->pause)
		return (0);
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '$')
			ft_get_player(p, line);
		else if (ft_ststr(line, "Plateau") && !p->map->map)
			ft_define_map(p, line);
		else if ((line[0] == '0' || line[0] == '1') && p->map->map)
			ft_create_map(p, line);
	}
}
