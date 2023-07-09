/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:35:27 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/30 14:35:27 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int average_pixel(int x, int y, t_data *data, t_line camera, t_plane vp);
static int average_colours(int c1, int c2, int c3, int c4);

void	create_vision_plane(t_data *data, t_plane *vp)
{
	t_camera 	*cam;

	cam = data->scene->camera;
	cam->vector = _divide(cam->vector, _len(cam->vector));
	vp->base = _add(cam->center, cam->vector);

	vp->v1 = _rotate(cam->vector, -90, 0);
	vp->v2 = _rotate(vp->v1, 0, 90);
}

t_vector	get_direction(t_data *data, t_plane vp, double x, double y)
{
	t_vector	start;
	double 		width;
	double 		height;

	width = 2 * tanf((data->scene->camera->degrees / 2) * M_PI / 180);
	height = width / (WIDTH / HEIGHT);
	start = _add(vp.base, _multiply(vp.v2, height / 2));
	start = _add(start, _multiply(vp.v1, width / 2));
	start = _add(start, _multiply(vp.v2, -y * (height / HEIGHT)));
	start = _add(start, _multiply(vp.v1, -x * (width / WIDTH)));
	return (_subtract(start, data->scene->camera->center));
}

void	draw_image(t_mlx_data *ui, t_data *data)
{
	int 	x;
	int 	y;
	int 	color;
	t_line	camera;
	t_plane	vp;

	x = 0;
	y = 0;
	create_vision_plane(data, &vp);
	camera.base = data->scene->camera->center;
	while (x < ui->width)
	{
		while (y < ui->height)
		{

			if (ANTI_ALIASING)
				color = average_pixel(x, y, data, camera, vp);
			else
			{
				camera.direction = get_direction(data, vp, x, y);
				color = trace_ray(data, camera, 0);
			}
			if (color != 0)
				put_pixel(x, y, color, data);
			color = 0;
			y++;
		}
		if (x % 3 == 0)
			mlx_put_image_to_window(ui->mlx, ui->win, ui->img, 0, 0);
		y = 0;
		x ++;
	}
}

static int average_pixel(int x, int y, t_data *data, t_line camera, t_plane vp)
{
	int c1;
	int c2;
	int c3;
	int	c4;

	camera.direction = get_direction(data, vp, x + 0.25f, y);
	c1 = trace_ray(data, camera, 0);
	camera.direction = get_direction(data, vp, x + 0.75f, y);
	c2 = trace_ray(data, camera, 0);
	camera.direction = get_direction(data, vp, x + 0.25f, y + 0.75f);
	c3 = trace_ray(data, camera, 0);
	camera.direction = get_direction(data, vp, x + 0.75f, y + 0.75f);
	c4 = trace_ray(data, camera, 0);
	return (average_colours(c1, c2, c3, c4));
}

static int average_colours(int c1, int c2, int c3, int c4)
{
	t_vector col1;
	t_vector col2;
	t_vector col3;
	t_vector col4;

	col1 = colour_to_vector(c1);
	col2 = colour_to_vector(c2);
	col3 = colour_to_vector(c3);
	col4 = colour_to_vector(c4);
	col1.x = (col1.x + col2.x + col3.x + col4.x) / 4;
	col1.y = (col1.y + col2.y + col3.y + col4.y) / 4;
	col1.z = (col1.z + col2.z + col3.z + col4.z) / 4;
	return (trgb(0, col1.x, col1.y, col1.z));
}
