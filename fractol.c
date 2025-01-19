#include "fractol.h"

int main(void)
{
	void *mlx;
	void *window;
	void *image;

	mlx = mlx_init ();
	window = mlx_new_window(mlx, size_x, size_y, "Fractol" );
	image = mlx_new_image(mlx, size_x, size_y);

	int bits_per_pixel;//the number of bits needed to represent a pixel color
	int size_line;//number of bytes used to store one line of the image in memory
	int endian;//tells you wether the pixel color in the image needs to be stored in little endian endian == 0, or big endian endian == 1.
	char *buffer;//address that represents the begining of the memory area where the image is stored.

	bits_per_pixel = 32; //forcé dans minilibx
	size_line = size_x * bits_per_pixel; //forcé dans minilibx
	endian = 0; //forcé dans minilibx
	buffer = mlx_get_data_addr(image, &bits_per_pixel, &size_line, &endian); //returns information about the created image, allowing a user to modify it later

	int x;
	int y;
	int c;

	c = 0;
	y = 0;
	while (y <= size_y - 1)
	{
		x = 0;
		while( x <= size_x)
		{
//			if(mandel(x ,y) == 1) //x%10 >= 3 && y%10 >=3
			buffer[((y * size_line) + x * 4)/1] = mandel(x ,y) ;
//			else if(mandel(x ,y) == 2)
//				buffer[(y * size_line) + x * 4] = color2;
			x++;
			c++;
		}
		y++;
	}
	printf("c = %d\n", c);
	mlx_put_image_to_window(mlx, window, image, 0, 0);

	mlx_loop(mlx);

//	mlx_destroy_image(mlx);

	return(0);
}


/*
//	mlx_pixel_put (mlx,window, 350, 350, 100);
	*/
