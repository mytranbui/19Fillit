/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:30:30 by mbui              #+#    #+#             */
/*   Updated: 2019/09/16 15:12:47 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int valid_tetro(char *str)
{
	int n;
	int i;

	n = 0;
	i = 0;
	/*if (!valid_map)
	{
		ft_putendl("error");
		return (0);
	}*/
	while (str[i])
	{
		if (str[i] == '#' && str[i + 1] == '#')
			n++;
		else if (str[i] == '#' && str[i + 5] == '#')
			n++;
		i++;
	}
	printf("n = %d\n", n);
	if (n == 3)
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	if (ac == 2)
		printf("%d\n", valid_tetro(av[1]));
	return (0);
}
