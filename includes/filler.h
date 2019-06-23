/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:44:19 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/16 10:14:28 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <fcntl.h>
#include <gssapi.h>
# include "libft.h"
# include "ft_printf.h"

typedef	struct		s_point
{
	int		x;
	int 	y;
}					t_point;

typedef struct		s_filler
{
	int 	fd;
	int 	player;
	int 	**map;
	int 	map_x;
	int 	map_y;
	char 	**fig;
	int 	fig_x;
	int 	fig_y;
}					t_filler;

void				ft_read_params(t_filler *filler, char *line);
void				ft_place_fig(t_filler *filler);
void				ft_heapmap(t_filler *filler);

#endif