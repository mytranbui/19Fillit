/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_filetest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:25:37 by mbui              #+#    #+#             */
/*   Updated: 2019/09/20 10:16:43 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"
#include <stdio.h>

char	*ft_read(int fd)
{
	char	*file;
	int		ret;
	int		i;

	i = 0;
	if (!(file = (char *)ft_strnew(546)))
		return (NULL);
	if ((ret = read(fd, file, 546)) <= 0)
		return (NULL);
	while (file[i] != '\0')
	{
		if (ret > 545 || (file[i] != '#' && file[i] != '\n' && file[i] != '.'))
			return (NULL);
		i++;
	}
	//printf("ret = %d\n", ret);
	return (file);
}

/*char	**free_tab(char **tab) //not sure if it works
  {
  int	i;

  i = 0;
  while (tab[i])
  free(tab[i++]);
  return (NULL);
  }
  */
/*void free_tab(int fd)
  {
  t_tetro tetri;
  int j;

  j = 0;
  tetri.tab = stock(fd);
  while (tab[j] != 0)
  {
  ft_strdel(&tab[j]);
  j++;
  }
  }
  */
char	**free_tab(char **tab, int i) // should be added to libft
{
	while (i >= 0)
		free(tab[i--]);
	return (NULL);
}

t_tetro	**stock(char *file)// t_tetro first_tetro
{
	t_tetro tetri;
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (file[i] != '\0')
	{
		tetri.tab[j] = ft_strncpy(tetri.tab[j], &file[i], 20);
		printf("bk%d = %s||", j, tetri.tab[j]);
		i += 21;
		j++;
	}
	return (tetri.tab);
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
			if (str[i - 1] == '#')
				n++;
			if (str[i + 1] == '#')
				n++;
			if (str[i + 5] == '#')
				n++;
			if (str[i - 5] == '#')
				n++;
		}
	}
	printf("linknb = %d\n", n);
	if (n == 6 || n == 8)
		return (1);
	return (0);
}

int		check_tetro(t_tetro tetri)
{
	int	n;
	int	m;
	int	i;
	int	j;

	j = 0;
	while (tetri.tab[j] != 0)
	{
		i = 0;
		n = 0;
		m = 0;
		while (tetri.tab[j][i])
		{
			if (tetri.tab[j][i] == '#')
				n++;
			if (tetri.tab[j][i] == '\n')
				m++;
			i++;
		}
		printf("j = %d\n", j);
		printf("n = %d et m = %d\n", n, m);
		if (n != 4 || m != 4 || (check_link(tetri.tab[j])) == 0)
			return (0);
//		if (n == 4 && m == 4 && check_link(tetri.tab[j]) == 1)
			j++;
	//	else //if (n != 4 || m != 4 || (check_link(tetri.tab[j])) == 0)
	//		return (0);
	}
	if (tetri.tab[j] == 0)
		return (1);
	return (0);
}
