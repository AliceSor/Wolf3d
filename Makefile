# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoroka <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 18:38:01 by asoroka           #+#    #+#              #
#    Updated: 2017/10/30 22:11:28 by asoroka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

FLAGS = -c -Wall -Wextra -Werror 

MLX = -lmlx -framework OpenGL -framework AppKit

HEADER = wolf3d.h

SRC = src/main.c				\
		src/create_win.c		\
		src/put_pixel.c			\
		src/create_map.c		\
		src/ray_casting.c		\
		src/buttons.c			\
		src/rotate.c			\
		src/create_xpm.c		\
		src/integrate_color.c	\
		src/create_image.c		\
		src/walls_color.c		\
		src/for_func.c 			\


BINS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
		gcc -o $(NAME) $(BINS) $(MLX)

%.o: %.c $(HEADER)
		gcc $(FLAGS) -o $@ $<

clean:
		/bin/rm -f $(BINS)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all
