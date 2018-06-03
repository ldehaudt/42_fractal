NAME = fractol

FLAGS = -Wall -Wextra -Werror

MINILIB = -I minilibx -L minilibx

FRAMEWORKS = -framework OpenGL -framework AppKit

SRC = main.c draw.c color.c fractals.c input.c

HEADER = fractol.h

LIBRARY = -L ./libft -lft

all : $(NAME)

$(NAME) :
	make -C libft
	gcc -O3 $(FLAGS) $(LIBRARY) $(MINILIB) -lmlx $(FRAMEWORKS) -I $(HEADER) $(SRC) -o $(NAME)

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all