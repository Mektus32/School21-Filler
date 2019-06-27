/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:44:30 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/24 17:44:32 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizator.h"
#include <stdio.h>

void	ft_init_par(t_params *p)
{
	p->mlx_ptr = mlx_init();
	p->win_ptr = mlx_new_window(p->mlx_ptr, WIDTHW, HEIGHTW, WINNAME);
	p->image = ft_memalloc(sizeof(t_image));
	//cчитать картинку для названия проекта
	p->map = ft_memalloc(sizeof(t_map));
	p->map->map_y = 0;
	p->map->map_x = 0;
	p->pause = 0;
	p->player1.color = 0xE32636;
	p->player2.color = 0x3C87B9;
	p->player1.bgcolor = 0xA75252;
	p->player2.bgcolor = 0x56588A;
	p->player1.score = 0;
	p->player2.score = 0;
}

int 	main(void)
{
	t_params	*p;

	open("/Users/ojessi/Desktop/Filler/one_map", O_RDWR | O_APPEND);
	open("/Users/ojessi/Desktop/Filler/resources/test", O_RDWR | O_APPEND);
	p = ft_memalloc(sizeof(t_params));
	ft_init_par(p);
	ft_read_param(p);
	ft_key_hook(p);
	ft_printf("{set:fd} p1 - %s p2 - %s map_y = %d map_x = %d", 3, p->player1.name, p->player2.name, p->map->map_y, p->map->map_x);
	mlx_loop(p->mlx_ptr);
	return (0);
}
