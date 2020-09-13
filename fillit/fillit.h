/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 13:00:57 by mbui              #+#    #+#             */
/*   Updated: 2019/09/24 11:00:11 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h> //open

# define MAX_READ 545
# define MAX_NB 26
# define TETRO_LEN 20
/*typedef struct 	s_liste
  {
  struct	s_tetro		*head_tetro;
  int size;
  }				t_liste;

  typedef	struct	s_tetro
  {
  int	type;
  char	lettre;
  struct s_tetro		*next;

  }				t_tetro;
  */
typedef struct	s_tetro
{
	int		nb;
	char	**tab;
//	char	*tab[26];
	//	void			*content;
	//	size_t			content_size;
	//	struct s_tetro	*next;
}				t_tetro;

typedef struct	s_solv
{
	double	size;
	char	**map;
}				t_solv;

char			*ft_read(int fd);
char			**stock(char *file);
//t_tetro		**stock(char *file);
int				check_link(char *str);
int				check_tetro(char **tab);
//int				check_tetro(t_tetro tetri);
double				which_size(int nb);
char			**init_map(double size);

#endif
