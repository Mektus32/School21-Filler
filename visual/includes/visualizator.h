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
# define WIDTHW 1200
# define HEIGHTW 600
# define WIDTHI 600
# define HEIGHTI 500
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
}					t_map;

typedef	struct		s_player
{
	char	*name;
	int 	color;
	int 	score;
	int 	bgcolor;
}					t_player;

typedef struct		s_params
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		*image;
	t_map		*map;
	int 		pause;
	t_player	player1;
	t_player	player2;
}					t_params;

void				ft_key_hook(t_params *p);
void				ft_read_param(t_params *p);
void				ft_draw(t_params *p);
void				ft_calc_score(t_params *p);
void				ft_draw_box(t_params *p, int color);

#endif
