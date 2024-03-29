/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 10:55:06 by mbui              #+#    #+#             */
/*   Updated: 2019/04/27 09:56:37 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;
	char		ch;

	i = 0;
	d = dst;
	s = src;
	while (i < n)
	{
		ch = *s;
		*d = ch;
		d++;
		s++;
		if (ch == (char)c)
			return (d);
		i++;
	}
	return (NULL);
}
