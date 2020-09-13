/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:21:29 by mbui              #+#    #+#             */
/*   Updated: 2019/09/24 11:09:58 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	*ft_read(int fd)
{
	char	*file;
	int		ret;
	int		i;

	i = -1;
	if (!(file = (char *)ft_strnew(MAX_READ + 1)))
		return (NULL);
	if ((ret = read(fd, file, MAX_READ + 1)) <= 0)
		return (NULL);
	while (file[++i])
		if (ret > MAX_READ ||
				(file[i] != '#' && file[i] != '\n' && file[i] != '.'))
			return (NULL);
	printf("ret = %d\n", ret);
	return (file);
}

char	**stock(char *file)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = NULL;
	if (!(tab = (char **)malloc(sizeof(char *) * MAX_NB)))
		return (NULL);
	while (file[i])
	{
		if (!(tab[j] = ft_strsub(file, i, TETRO_LEN)))
			return (free_tab(tab, j));
		printf("--- tab[%d] ---\n%s", j, tab[j]);
		i += (TETRO_LEN + 1);
		j++;
	}
	tab[j] = 0;
	return (tab);
}

int		check_link(char *str)
{
	int	i;
	int	n;

	i = -1;
	n = 0;
	while (str[++i])
	{
		if (str[i] == '#')
		{
			str[i - 1] == '#' ? n++ : n;
			str[i + 1] == '#' ? n++ : n;
			str[i - 5] == '#' ? n++ : n;
			str[i + 5] == '#' ? n++ : n;
		}
	}
	printf("linknb = %d\n", n);
	if (n == 6 || n == 8)
		return (1);
	return (0);
}

int		check_tetro(char **tab)
{
	int	j;
	int i;
	int nbchar[3];

	j = -1;
	while (tab[++j])
	{
		printf("tab[%d]:", j);
		i = -1;
		nbchar[0] = 0;
		nbchar[1] = 0;
		nbchar[2] = 0;
		while (tab[j][++i])
		{
			tab[j][i] == '#' ? nbchar[0]++ : nbchar[0];
			tab[j][i] == '\n' ? nbchar[1]++ : nbchar[1];
			tab[j][i] == '.' ? nbchar[2]++ : nbchar[2];
		}
		printf("# = %d & \\n = %d & . = %d\n", nbchar[0], nbchar[1], nbchar[2]);
		if ((nbchar[0] != 4 || nbchar[1] != 4 || nbchar[2] != 12) ||
				(check_link(tab[j])) != 1)
		{
			free_tab(tab, j);
			return (0);
		}
	}
	return (1);
}
