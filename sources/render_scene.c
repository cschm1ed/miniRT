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

#include "../includes/minirt.h"

void	create_vision_plane(t_data *data, t_plane *vp)
{
	t_camera 	*cam;

	cam = data->scene->camera;
	cam->vector = _divide(cam->vector, _len(cam->vector));
	vp->base = _add(cam->center, cam->vector);

	vp->v1 = _rotate(cam->vector, -90, 0);
	vp->v2 = _rotate(vp->v1, 0, 90);
}

t_vector	get_direction(t_data *data, t_plane vp, int x, int y)
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
			camera.direction = get_direction(data, vp, x, y);
			color = trace_ray(data, camera, 0);

			if (color != 0)
				put_pixel(x, y, color, data);
			color = 0;
			y++;
		}
		y = 0;
		x ++;
	}
}
