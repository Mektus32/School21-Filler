/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:34:59 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/28 10:35:03 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizator.h"

void	ft_init_p(t_params *p)
{
	open("/Users/ojessi/Desktop/Filler/one_map", O_RDWR | O_APPEND);
	open("/Users/ojessi/Desktop/Filler/resources/test", O_RDWR | O_APPEND);
	p->mlx_ptr = NULL;
	p->win_ptr = NULL;
	p->image = ft_memalloc(sizeof(t_image));
	p->image->bpp = 32;
	p->image->size_line = WIDTH * 4;
	p->image->endian = 0;
	p->map = NULL;
	p->pause = 0;
	p->left = 0;
	p->right = 0;
	p->slow = 0;
	p->fig = NULL;
}

void	ft_print_list(t_params *p)
{
	t_fig	*tmp;
	int 	i;

	tmp = p->fig;
	while (tmp)
	{
		i = -1;
		while (++i < tmp->fig_y)
			ft_printf("%s\n", tmp->fig[i]);
		ft_printf("y = %d\n", tmp->y);
		ft_printf("x = %d\n", tmp->x);
		ft_printf("player = %d\n", tmp->player);
		ft_printf("score = %d\n", tmp->score);
		tmp = ft_move_right(tmp, 1);
	}
}

int 	main(void)
{
	t_params	p;

	ft_init_p(&p);
	ft_read(&p);
	//ft_print_list(&p);
	ft_draw(&p);
	ft_key_hook(&p);
	mlx_loop(p.mlx_ptr);
	return (0);
}
