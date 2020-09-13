/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_filetest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:25:37 by mbui              #+#    #+#             */
/*   Updated: 2019/09/20 08:50:26 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"
#include <stdio.h>

char	*ft_read(int fd)
{	
	printf("MO");
	int ret;
	char *file;
	int i;

	i = 0;
	/*	if (file != NULL)
		{
		ft_strdel(file);
		return (NULL);
		}
		*/	if (!(file = (char *)ft_strnew(546)))
	return (NULL);
	if ((ret = read(fd, file, 546)) <= 0)
		return (NULL);
	while (file[i] != '\0')
	{
		if (ret > 545 || (file[i] != '#' && file[i] != '\n' && file[i] != '.'))
			return (NULL);
		i++;
	}
	printf("ret = %d\n", ret);
	return (file);
}

char	**stock(int fd)// t_tetro first_tetro
{	
	printf("CO");
	int i;
	int j;
	char	*file;
	t_tetro tetri;

	i = 0;
	j = -1;
	if ((file = ft_read(fd)) == NULL)
		return (NULL);
	while (file[i] != '\0')
	{
		tetri.tab[++j] = ft_strsub(file, i, 20);
		printf("bk%d = %s||",j, tetri.tab[j]);
		i += 21;
	}
	tetri.tab[j] = 0;
	return (tetri.tab);
}
/*
void free_tab(int fd)
{
	printf("VE");
	t_tetro tetri;
	int j;

	j = 0;
	tetri.tab = stock(fd);
	while (tetri.tab[j] != 0)
	{
		ft_strdel(&tetri.tab[j]);
		j++;
	}
	//	return (ft_read(fd));
}
*/
char	**free_tab(char **tab, int i)
{
	while (i >= 0)
		free(tab[i--]);
	return (NULL);
}

int check_link(char *str)
{
	printf("TI");
	int i;
	int n;

	i = -1;
	n = 0;
	//	while (str[++i])//&& (file[i] == '#' || file[i] == '.' || file[i] == '\n'))
	//		if (file[i] == '#')
	//			n++;
	//	i = -1;
	//	if (n = 4)
	//	{
	//		n = 0;
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
	if (n == 6 || n == 8)
		return (1);
	return (0);
}

int    check_tetro(int fd)
{
	printf("LO");
	int n;
	int i;
	int j;
	t_tetro tetri;

	n = 0;
	j = 0;
	if (!(tetri.tab = stock(fd)))
		return (-1);
	printf("RO");
	while (tetri.tab[j] != 0)
	{
		i = 0;
		while (tetri.tab[j][i])
		{
			if (tetri.tab[j][i] == '#' && n < 4)
				n++;
			if (tetri.tab[j][i] == '\n' && n >= 4)
				n++;	
			i++;
		} 
		printf("n = %d\n", n);
		if	(n == 8 && (check_link(tetri.tab[j])) == 1)
			j++;
		if	(n != 8)
		{
			free_tab(tetri.tab, j);
			return (0);
		}
		if	(check_link(tetri.tab[j]) == 0)
		{
			free_tab(tetri.tab, j);
			return (0);
		}
	}
	return (1);
}

/*int    check_tetro(int fd)
{
	printf("LO");
	int n;
	int i;
	int j;
	t_tetro tetri;

	n = 0;
	j = 0;
	if (!(tetri.tab = stock(fd)))
		return (-1);
	while (tetri.tab[j] != 0)
	{
		i = 0;
		while (tetri.tab[j][i])
		{
			if (tetri.tab[j][i] == '#' && n < 4)
				n++;
			if (tetri.tab[j][i] == '\n' && n >= 4)
				n++;	
			i++;
		}
		if	(n != 8 || (check_link(tetri.tab[j])) == 0)
		{
			free_tab(tetri.tab, j);
			return (0);
		}
		else if	(n == 8 && (check_link(tetri.tab[j])) == 1)
			j++;
	}
	return (1);
}*/

int main(int ac, char **av)
{
	/*	char *str0;
		char *str1;
		char *str2;
		char *str3;
		char *str4;
		char *str5;
		char *str6;
		char *str7;
		char *str8;
		char *str9;
		char *str10;
		char *str11;
		char *str12;
		char *str13;
		char *str14;
		char *str15;
		char *str16;
		char *str17;
		char *str18;
		char *str19;
		char *str20;
		char *str21;
		char *str22;

		str0 = "####\n....\n....\n....\n";
		str1 = "..##\n..#.\n..#.\n....\n";
		str2 = "..##\n...#\n...#\n....\n";
		str3 = "....\n##..\n.##.\n....\n";
		str4 = "....\n..##\n.##.\n....\n";
		str5 = "....\n..#.\n.###\n....\n";
		str6 = "....\n....\n..##\n..##\n";
		str7 = "...#\n...#\n...#\n...#\n";
		str8 = ".#..\n.###\n....\n....\n";
		str9 = "....\n....\n.###\n...#\n";
		str10 = ".#..\n.#..\n##..\n....\n";
		str11 = ".#..\n.##.\n.#..\n....\n";
		str12 = "....\n.#..\n##..\n.#..\n";
		str13 = "....\n....\n.###\n..#.\n";
		str14 = "....\n...#\n..##\n..#.\n";
		str15 = "....\n..#.\n..##\n...#\n";
		str16 = "....\n....\n.###\n.#..\n";
		str17 = "....\n....\n...#\n.###\n";
		str18 = "....\n.#..\n.#..\n.##.\n";
		str19 = "#...\n.#..\n..#.\n...#\n";
		str20 = "####\n####\n####\n####\n";
		str21 = "....\n....\n....\n....\n";
		str22 = ".##.\n....\n##..\n....\n";

		printf("str0 = %d\n", check_tetro(str0));
		printf("str1 = %d\n", check_tetro(str1));
		printf("str2 = %d\n", check_tetro(str2));
		printf("str3 = %d\n", check_tetro(str3));
		printf("str4 = %d\n", check_tetro(str4));
		printf("str5 = %d\n", check_tetro(str5));
		printf("str6 = %d\n", check_tetro(str6));
		printf("str7 = %d\n", check_tetro(str7));
		printf("str8 = %d\n", check_tetro(str8));
		printf("str9 = %d\n", check_tetro(str9));
		printf("str10 = %d\n", check_tetro(str10));
		printf("str11 = %d\n", check_tetro(str11));
		printf("str12 = %d\n", check_tetro(str12));
		printf("str13 = %d\n", check_tetro(str13));
		printf("str14 = %d\n", check_tetro(str14));
		printf("str15 = %d\n", check_tetro(str15));
		printf("str16 = %d\n", check_tetro(str16));
		printf("str17 = %d\n", check_tetro(str17));
		printf("str18 = %d\n", check_tetro(str18));
		printf("str19 = %d\n", check_tetro(str19));
		printf("str20 = %d\n", check_tetro(str20));
		printf("str21 = %d\n", check_tetro(str21));
		printf("str22 = %d\n", check_tetro(str22));
	*/	int fd;
	int res = 0;
	//char *str = "bonjour je m'appelle CLaire, le ciel est bleu et les roses sont jaunes.";

	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		res = check_tetro(fd);
		//res = div_file(fd);
		printf("res = %d\n", res);
	}
	return (0);
}
