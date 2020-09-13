/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:57:09 by mbui              #+#    #+#             */
/*   Updated: 2019/09/20 13:57:25 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <fcntl.h>

void convert_alpha(char **tab)
{
	char alpha;
	int j;
	int i;

	alpha = 'A';
	j = 0;
	i = 0;
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

void print()
{
	int i;
	int j;

	j = 0;
	while (j >= 0)
}
