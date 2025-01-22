#include "fractol.h"

int	exit_fractol(t_fractal *frac)
{
	mlx_destroy_image(frac->mlx, frac->image);
	mlx_destroy_window(frac->mlx, frac->window);
	free(frac->mlx);
	free(frac);
	exit(EXIT_SUCCESS);
	return (0);
}

void	error(void)
{
	ft_putendl_fd("entrez un des 3 parametres : julia, mandel, ship", 1);
	exit(EXIT_FAILURE);
}

void	display(t_fractal *frac)
{
	char	*zoom_char;
	char	*max_iter_char;

	zoom_char = ft_itoa(frac->zoom);
	max_iter_char = ft_itoa(frac->max_iter);

	create_image(frac);
	mlx_put_image_to_window(frac->mlx, frac->window, frac->image, 0, 0);
	print_logo(frac);
	create_image_pixel(frac);
	mlx_string_put(frac->mlx, frac->window, 10, 150, 0x00FF0000, "zoom (+/-) : ");
	mlx_string_put(frac->mlx, frac->window, 100, 150, 0x00FF0000, zoom_char);
	mlx_string_put(frac->mlx, frac->window, 10, 170, 0x0000FF00, "iteration (P/M) : ");
	mlx_string_put(frac->mlx, frac->window, 135, 170, 0x0000FF00, max_iter_char);
}

int	main(int argc, char **argv)
{
	t_fractal	*frac;

	frac = NULL;
	frac = init(frac, argc, argv);
	init_value(frac);
	mlx_mouse_hook(frac->window, mouse_hook, frac);
	mlx_key_hook(frac->window, key_hook, frac);
	mlx_hook(frac->window, 17, 0L, exit_fractol, frac);
	display(frac);
	mlx_loop(frac->mlx);
	return (0);
}
