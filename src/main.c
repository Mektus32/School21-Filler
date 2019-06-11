/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:45:24 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/11 18:42:11 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define N 5

void	ft_print_map(t_map *map, char field[N][N])
{
	int		i;
	int		j;
	
	i = -1;
	while (++i < map->size_y)
	{
		j = -1;
		while (++j < map->size_x)
			ft_printf("%2c", field[i][j]);
		ft_printf("\n");
	}
}

char	ft_calc_ves(int i, int j, char field[N][N], char c, t_map *map)
{
	int		ves;
	int		x;
	int		y;
	
	field[0][0] = 0;
	c = 'c';
	ves = 1;
	while (1)
	{
		y = i - ves - 1;
		while (++y < i + ves)
		{
			x = j - ves - 1;
			while (++x < j + ves)
			{
				
			}
		}
		ves++;
	}
}

void	ft_init_map(t_map *map, char field[N][N], char c)
{
	int		i;
	int		j;
	
	i = -1;
	while (++i < map->size_y)
	{
		j = -1;
		while (++j < map->size_x)
			field[i][j] = ft_calc_ves(i, j, field, c, map);;
	}
}

int		main(void)
{
	t_map	*map;
	char	c;
	char	field[N][N] =  {{'.', '.', '.', '.', '.'},
							{'.', '.', '.', '.', '.'},
							{'.', '.', 'x', '.', '.'},
							{'.', '.', '.', '.', '.'},
							{'.', '.', '.', '.', '.'}};
	map = ft_memalloc(sizeof(t_map));
	map->size_x = N;
	map->size_y = N;
	c = 'x';
	 ft_print_map(map, field);
	return (0);
}