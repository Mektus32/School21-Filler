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
	int 		j;
	static	int l = 0;

	j = -1;
	while (++j < p->map->map_x)
		p->map->map[i] = ft_strcpy(p->map->map[i], &line[4]);
	i++;
	if (i == p->map->map_y)
	{
		i = 0;
		//if (l < 3)
			ft_draw(p);
		l++;
	}
}

void	ft_get_player(t_params *p, char *line)
{
	static	int i = 0;
	char 		*str;
	int 		j;

	if (i == 2)
		return ;
	str = ft_strrchr(line, '/') + 1;
	j = 0;
	while (str[j] != '\0' && str[j] != '.')
		j++;
	if (i == 0)
		p->player1.name = ft_strsub(str, 0, j);
	else if (i == 1)
		p->player2.name = ft_strsub(str, 0, j);
	i++;

}

void	ft_read_param(t_params *p)
{
	char	*line;

	if (p->pause)
		return ;
	while (get_next_line(4, &line) > 0)
	{
		usleep(10000);
		if (line[0] == '$')
			ft_get_player(p, line);
		else if (ft_strstr(line, "Plateau") && !p->map->map)
			ft_define_map(p, line);
		else if ((line[0] == '0' || line[0] == '1') && p->map->map)
			ft_create_map(p, line);
		ft_strdel(&line);
	}
}
