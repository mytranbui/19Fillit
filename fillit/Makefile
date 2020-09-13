# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbui <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/06 09:43:02 by mbui              #+#    #+#              #
#    Updated: 2019/09/21 11:19:16 by mbui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror $(SRC) -L. -lft
	mv a.out $(NAME)

clean:
	rm -f $(OBJ) *.h.gch

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
