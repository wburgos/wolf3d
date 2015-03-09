#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/18 21:53:26 by wburgos           #+#    #+#              #
#    Updated: 2015/02/11 18:05:12 by wburgos          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d
SRCS = main.c image.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@make re -C libft/
	@echo "Compiling wolf ..."
	@gcc -c $(SRCS) -I. -Ilibft/includes
	@gcc -o $(NAME) $(OBJ) -Llibft -lft -lmlx -framework OpenGL -framework AppKit
	@echo "$(NAME) generated"

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
