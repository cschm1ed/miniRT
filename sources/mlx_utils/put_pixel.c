
#include "../../includes/minirt.h"

/**
 * put_pixel - places a pixel on the UI image
 * @x: the x-coordinate of the pixel
 * @y: the y-coordinate of the pixel
 * @color: the color of the pixel
 * @ui: pointer to the UI structure
 *
 * Puts a pixel with the specified color at the given coordinates in the UI image.
 */

void	put_pixel(int x, int y, int color, t_data *data)
{
	char		*dst;
	t_mlx_data	*ui;

	ui = &data->mlx_data;
	dst = ui->img_addr + (y * ui->line_length + x * ui->bits_per_pixel / 8);
	*(unsigned int *)dst = color;
}
