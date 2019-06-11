/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:44:19 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/11 17:58:15 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct		s_map
{
	int			size_x;
	int			size_y;
	char		*map;
}					t_map;

#endif