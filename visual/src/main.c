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
	p->map = ft_memalloc(sizeof(t_map));
	p->map->map_y = 0;
	p->map->map_x = 0;
	p->image = ft_memalloc(sizeof(t_image));
}

int 	main(void)
{
	t_params	*p;

	p = ft_memalloc(sizeof(t_params));
	ft_init_par(p);
	p->mlx_ptr = mlx_init();
	p->win_ptr = mlx_new_window(p->mlx_ptr, WIDTH, HEIGHT, WINNAME);
	mlx_loop(p->mlx_ptr);
	return (0);
}
