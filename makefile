//cc fractol.c calc_frac.c -L minilibx -lmlx -framework OpenGL -framework Appkit

NAME = fractol

PROG =	main\

SRC = $(addsuffix .c, $(PROG))

OBJ = $(addsuffix .o, $(PROG))

CC = cc

CFLAGS = -Wall -Wextra -Werror

all  :		$(NAME)

$(NAME) :	$(OBJ)
//			ar rcs $(NAME) $(OBJ)
			$(CC) $(OBJ) -o $(NAME)

%.o :		%.c
			$(CC) -c $< $(CFLAGS) -o $@

clean :
			rm -f $(OBJ)

fclean : 	clean
			rm -f $(NAME)

re : 		fclean all

.PHONY : 	all clean fclean re
