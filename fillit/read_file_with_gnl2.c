/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:03:09 by mbui              #+#    #+#             */
/*   Updated: 2019/09/11 13:39:01 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"
#include <stdio.h>

int	check_symbols(int fd, char **file)
{
	int i;
	int ret;
	char *lg;

	i = 0;
	printf("TO");
	while ((ret = get_next_line(fd, file)) == 1)
	{
		printf("JO");
		printf ("la ligne = %s\n", file[i]);
		if (*file[i] != '#' && *file[i] != '.' && *file == NULL)
			return (-2);
		else
			lg =
	}
	if (ret == -1)
		return (-3);
	return (1);
}

int div_file_to_blocks(int fd, char *file)
{
	int i;
	int j;
	int l;
	int ro;
	char **bk;

	i = 0;
	l = 0;
	j = 0;
	ro = 0;
	bk = NULL;
	printf("MO");
	if (check_symbols(fd, &file) != 1)
	{
		printf("PO");
		return (-4);
	}
	while (file[i])
	{
			//bk = ft_strsplit(file, NULL);
			bk[l] = ft_strsub(file, i, 20);
			i += 21;
			l++;
		//	j += 5;
			printf("NOW\n = %s", bk[l]);
		//if (file[j] == NULL)
		//	j++;
		//j++;
		//return (-5);
	}
	return (1);
}

int	check_tetro(int fd, char **file)
{
	int n;
	int i;

	n = 0;
	i = 0;
	if ((check_symbols(fd, file)) == 0)
	{
		ft_putendl("error");
		return (0);
	}
	while (*file[i])
	{
		if (*file[i] == '#' && *file[i + 1] == '#')
			n++;
		else if (*file[i] == '#' && *file[i + 5] == '#')
			n++;
		i++;
	}
	if (n == 3)
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	int fd;
	printf("LO");

	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		printf("%d\n", div_file_to_blocks(fd, av[1]));
	}
	return (0);
}
/*
   int first_read()
   {
   while (get_next_line(fd, &line) > 0)
   {

   }
   while (read(file, 545) > 0)
   {
   cut_file()
   }
   }

   int	cut_file(char *file, char **tetro)
   {

   }*/
