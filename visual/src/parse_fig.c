/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 11:44:28 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/29 19:44:34 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizator.h"

int		*ft_get_params_fig(char *line, int *par)
{
	int		i;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	par[4] = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	par[3] = ft_atoi(&line[i]);
	return (par);
}

char	**ft_fill_fig(char *str, char **fig, int *par)
{
	static	int		i = 0;
	int				j;

	if (!fig)
	{
		i = 0;
		fig = ft_memalloc(sizeof(char *) * (par[4] + 1));
		fig[par[4]] = NULL;
		j = -1;
		while (++j < par[4])
		{
			fig[j] = ft_memalloc(sizeof(char) * (par[3] + 1));
			fig[j][par[3]] = '\0';
		}
	}
	fig[i] = ft_strcpy(fig[i], str);
	i++;
	return (fig);
}

int		*ft_read_score(int *par, char **fig, int *score)
{
	int		i;
	int		j;
	int		count;

	i = -1;
	count = 0;
	while (++i < par[4])
	{
		j = -1;
		while (++j < par[3])
			if (fig[i][j] == '*')
				count++;
	}
	*score += count - 1;
	par[5] = *score;
	return (par);
}

int		*ft_get_got(char *str, int *par, char **fig)
{
	int				i;
	static	int		scorep1 = 0;
	static	int		scorep2 = 0;

	if (str[6] == 'X')
	{
		par = ft_read_score(par, fig, &scorep1);
		par[2] = -1;
	}
	else if (str[6] == 'O')
	{
		par[2] = 0;
		par = ft_read_score(par, fig, &scorep2);
	}
	i = 0;
	while (!ft_isdigit(str[i]))
		i++;
	par[1] = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	i++;
	par[0] = ft_atoi(&str[i]);
	return (par);
}

void	ft_parse_fig(t_params *p, char *line)
{
	int				*par;
	char			**fig;
	char			*str;
	t_fig			*tmp;

	par = ft_memalloc(sizeof(int) * 6);
	par = ft_get_params_fig(line, par);
	fig = NULL;
	while (get_next_line(0, &str) > 0 && !ft_strstr(str, "<got"))
	{
		fig = ft_fill_fig(str, fig, par);
		ft_strdel(&str);
	}
	par = ft_get_got(str, par, fig);
	str ? ft_strdel(&str) : 0;
	if (!p->fig)
	{
		tmp = ft_create_elem(&par, fig, NULL);
		p->fig = &tmp;
	}
	else if (*p->fig)
		ft_push_back(p->fig, &par, fig);
}
