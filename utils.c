#include "fractol.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (t1[i] == t2[i] && t1[i] && t2[i] && i + 1 < n)
		i++;
	return (t1[i] - t2[i]);
}

t_fractal *init(t_fractal *frac, int argc, char** argv)
{
	if(argc <= 1)
		error();
	frac = malloc(sizeof(t_fractal));// a proteger et leaks
	frac->name = OTHER;
	if(ft_strncmp(argv[1], "julia", 6) == 0)
		frac->name = JULIA;
	if(ft_strncmp(argv[1], "mandel", 7) == 0)
		frac->name = MANDEL;
	if(frac->name == OTHER)
	{
		free(frac);
		error();
	}
	frac->mlx = mlx_init ();
	frac->window = mlx_new_window(frac->mlx, SIZE_X, SIZE_Y, "fractol");
	frac->image = mlx_new_image(frac->mlx, SIZE_X, SIZE_Y);
	frac->bits_per_pixel = 32;
	frac->size_line = SIZE_X * frac->bits_per_pixel;
	frac->endian = 0;
	frac ->buffer = mlx_get_data_addr(frac->image, &frac->bits_per_pixel, &frac->size_line, &frac->endian);
	return (frac);
}

void init_value(t_fractal *frac)
{
	frac->color = 0xFCBE11; //0xFCBE11
	frac->zoom = 250;
	frac->growth = 1.1;
	frac->max_iter = 50;
	if(frac->name == MANDEL)
	{
		frac->o_x = -700;
		frac->o_y = -400;
		frac->move = 50;
		frac->p = 0;
		frac->pa = 0;
		frac->pb = 0;
	}
	if(frac->name == JULIA)
	{
		frac->o_x = -550;
		frac->o_y = -375;
		frac->move = 100;
		frac->p = 0.05;
		frac->pa = -0.16;
		frac->pb = 0.88;
	}
}
