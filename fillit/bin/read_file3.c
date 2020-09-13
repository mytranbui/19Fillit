/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:03:09 by mbui              #+#    #+#             */
/*   Updated: 2019/09/12 15:28:23 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"
#include <stdio.h>

/*int ft_read(int fd)
{
	char *buf;
//	char **tetri;
	int ret;
	int count;
	int i;

	i = 0;
	MALLOK((buf = ft_strnew(21)));
	if ((ret = read(fd, buf, 20)) < 0)
		return (-8);
	count = ret / 20;
	while (buf[i] != '\0')
	{
		printf("lettre = %c\n", buf[i]);
		if (buf[i] != '#' && buf[i] != '.' && buf[i] != '\n')
			return (-6);
		i++;
	}
	return (1);
}*/

/*int check_char(int fd, int ret)
{
	char **tetri;
	int i;

	i = 0;
	if (ft_read(fd, ) == 1)
		tetri[i] = ft_strdup(buf);
	else
	{
		while (i != 0)
		{
			free(tetri[i]);
			i--;
		}
	}
}*/

/*read by one tetro*/
int div_file(char *file)// t_tetro first_tetro
{
	printf("HO");
	int i;
	int j;
	int k;
	int n;
	char tetro[26][21];

	i = 0;
	j = 0;
	n = 0;
	k = 0;
	tetro = NULL;
/*	if (check_char(fd) < 0)
	{
		printf("%d\n", check_char(fd));
		return (-5);
	}
*/	while (file[i] != '\0')
	{
		printf("PO");
		if (file[i] == '\n')
			k++;
		tetro[j++] = ft_strsub(file, i, 20);
		printf("bk = %s\n", tetro[j]);
		i = i + 21;
	}
	return (1);
}

int	check_char(int fd)
{
	printf("GO");
	int i;
	int ret;
	t_solv solver;
	t_tetro block;
	char *file;

	i = 0;
	MALLOK((file = ft_strnew(546)));
	if ((ret = read(fd, file, 545)) == -1)
		return (-2);
	while (file[i] != '\0')
	{
		printf("la lettre = %c\n", file[i]);
	 	if (file[i] != '#' && file[i] != '.' && file[i] != '\n')
			return (-3);
		i++;
	}
	block.nb = i / 20;
	solver.size = block.nb * 4;
	//printf("i = %d\n", i);
	//printf("nb = %d\n", count);
	//table = ft_strnew(4 * count); later in solver
	if (file[i] == '\0')
		return (1);
	i = 0;
	if (div_file(file) < 0)
		return (-9);
	return (-4);
}

/*int div_file(char *file)// t_tetro first_tetro
{
	printf("HO");
	int i;
	int j;
	int k;
	int n;
	char **tetro;

	i = 0;
	j = 0;
	n = 0;
	k = 0;
	tetro = NULL;
	//if (check_char(fd) < 0)
	//{
	//	printf("%d\n", check_char(fd));
	//	return (-5);
	//}
	while (file[i] != '\0')
	{
		printf("PO");
		if (file[i] == '\n')
			k++;
		tetro[j++] = ft_strsub(file, i, 20);
		printf("bk = %s\n", tetro[j]);
		i = i + 21;
	}
	return (1);
}
*/
int	check_tetro(int fd, char *file)
{
	int n;
	int i;

	n = 0;
	i = 0;
	if ((check_char(fd)) == 0)
	{
		ft_putendl("error");
		return (0);
	}
	while (file[i])
	{
		if (file[i] == '#' && file[i + 1] == '#')
			n++;
		else if (file[i] == '#' && file[i + 5] == '#')
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

	printf("KO");
	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		printf("%d\n", check_char(fd));
	}
	return (0);
}
