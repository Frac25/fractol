#include "fractol.h"

int main(void)
{
	void *mlx;
	void *window;
	void *image;
	void *image_ptr;

	mlx = mlx_init ();
	window = mlx_new_window(mlx, size_x, size_y, "Fractol" );
	image = mlx_new_image(mlx, size_x, size_y);
	mlx_pixel_put (mlx,window, 500, 500, 100);


//mlx_loop
	mlx_new_image()
//	image_ptr = mlx_get_data_adrr()



	return(0);
}


