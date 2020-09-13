/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:15:45 by mbui              #+#    #+#             */
/*   Updated: 2019/09/24 11:22:52 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	**init_map(double *size)
{
	char **map;
	int i;
	int j;

	j = -1;
	if (!(map = (char **)ft_memalloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (++j < size)
	{
		if(!(map[j] = (char *)ft_strnew(sizeof(char) * size + 1)))
			return (NULL);
		i = 0;
		while (i < size)
			map[j][i++] = '.';
	}
	return (map);
}

void convert_alpha(char **tab) //necessary ?
{
	char alpha;
	int j;
	int i;

	alpha = 'A';
	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (tab[j][i] = '#')
				tab[j][i] = alpha;
			i++;
		}
		j++;
		alpha++;
	}
}

int	add_tetro(t_solv, t_tetro tetri, int j, int y)
{
	int y;
	int x;

	while (tetro.tab[j][i])
	{
		if (tetro.tab[j][i] != '#')
			solvi.map[y][x] == A
	}
}

int solver(t_solv solvi, t_tetro tetri, int x)
{
	t_solv solvi;
	int i;
	int j;

	i = 0;
	j = 0;
	if (solvi.size == 0)
		solvi.size = ft_sqrt(tablen(tetri.tab) * 4);
	solvi.map = init_map(size);
	convert_alpha(tetri.tab); //hmmm
	if (map[j][i] != '.')
		return (solver(solvi, tetri, x + 1));
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if ()
		}
	}
	solvi.map = init_map(&solvi.size + 1);
}
