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
# define WIDTH 1200
# define HEIGHT 600

# include "libft.h"
# include "mlx.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "filler.h"


typedef	struct		s_fig
{
	int 			x;
	int 			y;
	int 			player;
	int 			score;
	char 			**fig;
	int 			fig_x;
	int 			fig_y;
	struct	s_fig	*next;
	struct	s_fig	*prev;
	int 			sim_y;
	int 			sim_x;
}					t_fig;

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
	int 	done;
}					t_map;

typedef	struct		s_player
{
	char	*name;
	int 	color;
	int 	bgcolor;
	int 	id;
	int 	score;
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
	t_fig		*fig;
	int 		left;
	int 		right;

}					t_params;

t_fig				*ft_create_elem(int **par, char **fig, t_fig *prev);
t_fig				*ft_push_back(t_fig	**head, int **par, char **fig);
t_fig				*ft_move_right(t_fig *cur, int step);
t_fig				*ft_move_left(t_fig *cur, int step);
void				ft_read(t_params *p);
void				ft_parse_fig(t_params *p, char *line);
void				ft_draw(t_params *p);
void 				ft_key_hook(t_params *p);
void				ft_print(t_params *p, t_fig *cur);

#endif
