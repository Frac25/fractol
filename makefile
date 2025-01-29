NAME = fractol

PROG =	calc_frac\
		display\
		fractol\
		hook\
		init\
		utils\


SRC = $(addsuffix .c, $(PROG))

OBJ = $(addsuffix .o, $(PROG))

CC = cc

CFLAGS = -Wall -Wextra -Werror

CFLAGS_2 = -L minilibx -l mlx -framework OpenGL -framework Appkit -lz

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) $(CFLAGS) $(CFLAGS_2) -o $(NAME)

%.o:		%.c
			$(CC) -c $< $(CFLAGS) -o $@

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

a:			fclean all clean

.PHONY:		all clean fclean re a
