/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:44:19 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/15 15:21:16 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"

typedef	struct		s_map
{
	int		size_x;
	int		size_y;
	int		sum;
	char	**map;
}					t_map;

typedef	struct		s_fig
{
	int		size_x;
	int		size_y;
	char	**fig;
}					t_fig;

typedef	struct		s_filler
{
	t_map	*map;
	t_fig	*fig;
	int		player;
	int		fd;
}					t_filler;

void		ft_get_param(t_filler *filler);

#endif