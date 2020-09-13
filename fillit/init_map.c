/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:36:52 by mbui              #+#    #+#             */
/*   Updated: 2019/09/23 20:00:18 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"
#include <fcntl.h>
#include <math.h>

double which_size(int nb)
{
	double size;

//	if (nb < 0 || nb > 26)
//		return (0);
	size = ft_sqrt(nb * 4);
//	if (nb != 1 && nb != 4 && nb != 9 && nb != 16 && nb != 25)
////		size++;
	return (size);
}

char	**init_map(double size)
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

int main(int ac, char **av)
{
	char **map;
	double size;
	int nb;
	int i;

	i = 0;
	if (ac > 1)
	{
		nb = ft_atoi(av[1]);
		if ((size = which_size(nb)) != 0)
		{
			printf("%f\n", size);
			map = init_map(size);
			while (i < size)
				printf("%s\n", map[i++]);
		}
	}
	return (0);
}
