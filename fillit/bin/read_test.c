/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:07:06 by mbui              #+#    #+#             */
/*   Updated: 2019/09/17 14:20:37 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "../fillit.h"

int main(int ac, char **av)
{
	int fd;
	int ret;
	char *file = NULL;

	 if (ac > 1)
	 {
		file = ft_strnew(170);
		fd = open(av[1], O_RDONLY);
		ret = read(fd, file, 21);
		printf("%s||\n", file);
		printf("ret = %d\n", ret);
	 }
	return 0;
}
