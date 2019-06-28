/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 11:14:45 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/28 11:14:46 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizator.h"

void	ft_init_player(t_params *p, char *line)
{
	char	*str;
	int 	i;


	if (!(str = ft_strrchr(line, '/')))
		str = &line[15];
	str++;
	i = 0;
	while (str[i] != '\0' && str[i] != '.')
		i++;
	if (ft_strstr(line, "p1"))
	{
		p->player1.name = ft_strsub(str, 0, i);
		p->player1.id = 0;
		p->player1.bgcolor = 0xA75252;
		p->player1.color = 0xE32636;
	}
	else if (ft_strstr(line, "p2"))
	{
		p->player2.name = ft_strsub(str, 0, i);
		p->player2.id = -1;
		p->player2.bgcolor = 0x56588A;
		p->player2.color = 0x3C87B9;
	}
}

void	ft_init_map(t_params *p, char *line)
{
	int		i;

	p->map = ft_memalloc(sizeof(t_map));
	p->map->done = 0;
	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	p->map->map_y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	p->map->map_x = ft_atoi(&line[i]);
	p->map->map = ft_memalloc(sizeof(char*) * (p->map->map_y + 1));
	p->map->map[p->map->map_y] = NULL;
	i = -1;
	while (++i < p->map->map_y)
	{
		p->map->map[i] = ft_memalloc(sizeof(char) * (p->map->map_x + 1));
		p->map->map[i][p->map->map_x] = '\0';
	}
}

void	ft_fill_map(t_params *p, char *line)
{
	static	int 	i = 0;
	int				j;

	j = -1;
	p->map->map[i] = ft_strcpy(p->map->map[i], &line[4]);
	i++;
	if (i == p->map->map_y)
		p->map->done = 1;
}

void	ft_read(t_params *p)
{
	char 	*line;

	while (get_next_line(4, &line) > 0)
	{
		ft_printf("{set:fd} %s\n", 3, line);
		if (line[0] == '$')
			ft_init_player(p, line);
		else if (ft_strstr(line, "Plateau") && !p->map)
			ft_init_map(p, line);
		else if ((line[0] == '0' || line[0] == '1') && !p->map->done)
			ft_fill_map(p, line);
		else if (ft_strstr(line, "Piece"))
			ft_parse_fig(p, line);
		ft_strdel(&line);
	}
}
