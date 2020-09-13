/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainchecktetro.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:16:41 by mbui              #+#    #+#             */
/*   Updated: 2019/09/20 12:19:25 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	char *str0;
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
	int fd;
	int res = 0;
	//char *str = "bonjour je m'appelle CLaire, le ciel est bleu et les roses sont jaunes.";

	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		res = ft_read(fd);
		//res = div_file(fd);
		printf("res = %d\n", res);
	}
	return (0);
}
