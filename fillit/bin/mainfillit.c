/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainfillit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 12:33:18 by mbui              #+#    #+#             */
/*   Updated: 2019/09/04 17:22:34 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h> //read
#include <sys/uio.h> //read
#include <stdlib.h>
#include <fcntl.h> //open
#include "libft.h"
#include "fillit.h"

int		valid_map(char *str)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	if (ft_strlen(str) == 20)
	{
		while (*str)
		{
			if (*str == '#')
				i++;
			if (*str == '.')
				j++;
			if (*str == '\n')
				k++;
			str++;
		}
	}
	if (i == 4 && j == 12 && k == 4)
		return (1);
	return (0);
}

int valid_block(char *str)
{
	int n;

	n = 0;
	if (!valid_map)
	{
		ft_putendl("error");
		return (0);
	}
	while (str[i])
	{
		if (str[i] == '#' && str[i + 1] == '#')
			n++;
		else if (str[i] == '#' && str[i + 5] == '#')
			n++;
		i++;
	}
	if (n == 3)
		return (1);
	return (0);
}

int	valid_sample(char *str)
{
	if (!valid_block(str))
		return (0);
}

void	assemble(char *str)
{

}

void	convert_to_alpha(char *str)
{
	if (!assemble)
	{
		ft_putendl("error");
		return (0);
	}

}

int main(int argc, char **argv)
{
	if (argc == 2)
		fillit(argv[1]);
	if (!(open(argv[1], O_RDONLY)))
		ft_putendl("error");
	return (0);
}
