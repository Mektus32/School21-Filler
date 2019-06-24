/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 22:46:22 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/24 22:46:23 by ojessi           ###   ########.fr       */
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
	return (0);
}

void	ft_key_hook(t_params *p)
{
	mlx_hook(p->win_ptr, 2, 0, keyboard, p);
	mlx_hook(p->win_ptr, 17, 0, expose, p);
}
