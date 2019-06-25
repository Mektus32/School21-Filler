/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizator.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:45:10 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/24 17:45:10 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZATOR_H
# define VISUALIZATOR_H

# include "libft.h"
# include "mlx.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "filler.h"
# define WIDTH 1200
# define HEIGHT 600
# define WINNAME "Filler visualizator"

typedef	struct		s_image
{
	void	*img_ptr;
	char 	*img_data;
	int 	bpp;
	int 	size_line;
	int 	endian;
}					t_image;

typedef struct 		s_map
{
	char 	**map;
	int 	map_y;
	int 	map_x;
	int 	read;
}					t_map;

typedef struct		s_params
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	*image;
	t_map	*map;
	int 	pause;
	char	*player1;
	char	*player2;
}					t_params;

void				ft_key_hook(t_params *p);
void				ft_read_param(t_params *p);

#endif
