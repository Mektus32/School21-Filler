/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:44:19 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/29 19:41:25 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"

typedef	struct		s_point
{
	int		x;
	int		y;
}					t_point;

typedef struct		s_filler
{
	t_point	mapcor;
	int		sum;
	int		fd;
	int		player;
	char	**map;
	int		map_x;
	int		map_y;
	char	**fig;
	int		fig_x;
	int		fig_y;
}					t_filler;

void				ft_read_params(t_filler *filler, char *line);
void				ft_place_fig(t_filler *filler);
int					**ft_heapmap(t_filler *filler, int **mapint);

#endif
