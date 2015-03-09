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
SDIR = src/
INC = includes/
FILES = main.c ft_putpix.c die.c get_next_line.c read_map.c ft_nbrsplit.c \
		ft_drawline.c print_map.c
OBJ = $(FILES:.c=.o)
SRC = $(addprefix $(SDIR), $(FILES))
FLAGS = -Wall -Wextra

all: $(NAME)

$(NAME):
	# @make re -C libft/
	# @make re -C minilibx/
	@echo "Compiling wolf ..."
	@gcc $(FLAGS) -c $(SRC) -I$(INC) -Ilibft/includes
	@gcc -o $(NAME) $(OBJ) -L/usr/X11/lib -Llibft -lmlx -lXext -lX11 -lft
	@echo "$(NAME) generated"

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
