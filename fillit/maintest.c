/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 11:25:03 by mbui              #+#    #+#             */
/*   Updated: 2019/09/21 11:30:33 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_tetro	tetri;
//	t_solv	solvi;
	char	*file;
	int		res;
	int		fd;

	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		if ((file = ft_read(fd)) == NULL)
		{
			printf("wrong char/+545/empty/∃!");
			ft_strdel(&file);
			return (-1);
		}
		tetri.tab = stock(file); //  protect ?
		if ((res = check_tetro(tetri.tab)) == 0)
		{
			printf("res1 = %d\n", res);
			ft_strdel(&file);
			return (-1);
		}
		printf("res2 = %d\n", res);
		res = tablen(tetri.tab);
		printf("nb = %d\n", res);
	//	solvi.map = init_map(which_size(tablen(tetri.tab)));
	}
	return (0);
}
