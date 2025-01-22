//cc fractol.c calc_frac.c hook.c utils.c init.c display.c -L minilibx -lmlx -framework OpenGL -framework Appkit -lz
NAME = fractol

PROG =	calc_frac\
		fractol\
		hook\
		init\
		display\
		utils\


SRC = $(addsuffix .c, $(PROG))

OBJ = $(addsuffix .o, $(PROG))

CC = cc

CFLAGS = -Wall -Wextra -Werror

CFLAGS_2 = -L minilibx -lmlx -framework OpenGL -framework Appkit -lz

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
