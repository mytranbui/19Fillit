/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 10:52:08 by mbui              #+#    #+#             */
/*   Updated: 2019/10/17 15:53:59 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**free_tab(char **tab, int i)
{
	while (i >= 0)
		ft_strdel(&tab[i--]);
	free(tab);
	tab = NULL;
	return (NULL);
}
