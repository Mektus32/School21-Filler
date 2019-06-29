/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:45:51 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/28 10:45:53 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizator.h"

t_fig	*ft_create_elem(int **par, char **fig, t_fig *prev)
{
	t_fig	*list;

	if (!(list = ft_memalloc(sizeof(t_fig))))
		return (NULL);
	list->x = (*par)[0];
	list->y = (*par)[1];
	list->player = (*par)[2];
	list->fig = fig;
	list->fig_x = (*par)[3];
	list->fig_y = (*par)[4];
	list->sim_x = 0;
	list->sim_y = 0;
	list->color = 0;
	list->score = (*par)[5];
	list->prev = prev;
	list->next = NULL;
	free(*par);
	return (list);
}

t_fig	*ft_push_back(t_fig **head, int **par, char **fig)
{
	t_fig *list;

	list = *head;
	while (list->next)
		list = list->next;
	list->next = ft_create_elem(par, fig, list);
	return (list->next);
}

t_fig	*ft_move_right(t_fig *cur, int step)
{
	t_fig	*list;

	list = cur;
	if (list)
		while (list->next && step-- > 0)
			list = list->next;
	return (list);
}

t_fig	*ft_move_left(t_fig *cur, int step)
{
	t_fig	*list;

	list = cur;
	if (list)
		while (list->prev && step-- > 0)
			list = list->prev;
	return (list);
}
