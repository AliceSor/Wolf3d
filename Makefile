NAME = Wolf3d

FLAGS = -c -Wall -Wextra -Werror 

MLX = -lmlx -framework OpenGL -framework AppKit

HEADER = wolf3d.h

SRC = src/main.c				\
	  	src/create_image.c		\
		src/create_win.c		\
		src/putPixel.c			\
		src/createMap.c			\
		src/findRay.c			\
		src/putColumn.c			\
		src/rayCasting.c		\


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
