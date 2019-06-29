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
	p->player2.name = ft_strdup("Default");
	p->player2.id = -1;
	p->player2.bgcolor = 0x56588A;
	p->player2.color = 0x3C87B9;
	p->player1.name = ft_strdup("Default");
	p->player1.id = -1;
	p->player1.bgcolor = 0x56588A;
	p->player1.color = 0x3C87B9;
}

int 	main(void)
{
	t_params	p;

	ft_init_p(&p);
	ft_read(&p);
	ft_draw(&p);
	ft_key_hook(&p);
	mlx_loop(p.mlx_ptr);
	return (0);
}
