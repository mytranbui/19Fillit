/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:03:09 by mbui              #+#    #+#             */
/*   Updated: 2019/09/11 14:43:20 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include "fillit.h"
#include <stdio.h>

int valid_file(int fd, char *file)
{
	int i;
	int j;
	int co = 0;

	i = 4;
	j = 0;
	if (!((read(fd, file, 545) > 0)))
		return (-2);
	while (file[i] != '\0')
	{
		if (j == 4)
		{
			i++;
			j = 0;
		}
		else if (file[i] == '\n' || j < 4)
		{
			co++;
			i+=5;
			j++;
		}
		else
			return (-1);
	}
	printf("%d\n", co);
	//if (i % 4 == 0)
	//	return (1);
	return (1);
}

int main(int ac, char **av)
{
	int fd;

	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		//printf("%s\n", av[1]);
		printf("%d\n", valid_file(fd, av[1]));
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
