/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:05:11 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/28 14:05:14 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizator.h"

int 	expose(void *param)
{
	t_params *p;

	p = param;
	(void)p;
	exit(0);
	return (0);
}

int 	keyboard(int key, void *param)
{
	t_params *p;

	p = param;
	if (key == 53)
		exit(0);
	if (key == 49)
		p->pause = (p->pause + 1) % 2;
	if (key == 124)
	{
		p->right = 1;
		p->left = 0;
	}
	if (key == 123)
	{
		p->right = 0;
		p->left = 1;
	}
	ft_draw(p);
	return (0);
}

void	ft_key_hook(t_params *p)
{
	mlx_hook(p->win_ptr, 2, 0, keyboard, p);
	mlx_hook(p->win_ptr, 17, 0, expose, p);
}
