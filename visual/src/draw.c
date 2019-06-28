/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 13:54:04 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/28 13:54:05 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizator.h"

void	ft_init_image(t_params *p)
{
	int 	*arr;

	p->image->img_ptr ? mlx_destroy_image(p->mlx_ptr, p->image->img_ptr) : 0;
	if (!p->image->img_ptr)
		p->image->img_ptr = mlx_new_image(p->mlx_ptr, WIDTH, HEIGHT);
	p->image->img_data = mlx_get_data_addr(p->image->img_ptr, &p->image->bpp,
			&p->image->size_line, &p->image->endian);
}

void	ft_create_image(t_params *p, t_fig *cur)
{

}

void	ft_draw(t_params *p)
{
	static	t_fig	*cur = NULL;

	if (!cur)
		cur = p->fig;
	!p->mlx_ptr ?  p->mlx_ptr = mlx_init() : 0;
	!p->win_ptr ?  p->win_ptr = mlx_new_window(p->mlx_ptr, WIDTH, HEIGHT, "Filler") : 0;
	if (!p->pause && p->right)
	{
		ft_printf("right");
		ft_init_image(p);
		cur = ft_move_right(cur, 1);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->image->img_ptr, 0, 0);
	}
	else if (!p->pause && p->left)
	{
		ft_printf("left");
		ft_init_image(p);
		cur = ft_move_left(cur, 1);
		ft_create_image(p, cur);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->image->img_ptr, 0, 0);
	}
}