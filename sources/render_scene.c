/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:35:27 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/20 13:15:34 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void	render_image(t_data *data, t_line *camera, t_plane *vp, int x);

static void	create_vision_plane(t_data *data, t_plane *vp)
{
	t_camera	*cam;

	cam = data->scene->camera;
	cam->vector = _divide(cam->vector, _len(cam->vector));
	vp->base = _add(cam->center, cam->vector);
	vp->v1 = _cross(cam->vector, (t_vector){0, 0, 1});
	vp->v1 = _divide(vp->v1, _len(vp->v1));
	vp->v2 = _cross(cam->vector, vp->v1);
	vp->v2 = _multiply(_divide(vp->v2, _len(vp->v2)), -1);
}

int	draw_image(t_data *data)
{
	t_line	camera;
	t_plane	vp;

	create_vision_plane(data, &vp);
	camera.base = data->scene->camera->center;
	render_image(data, &camera, &vp, 0);
	return (SUCCESS);
}

void	render_image(t_data *data, t_line *camera, t_plane *vp, int x)
{
	int	y;
	int	color;

	while (x < data->mlx_data.width)
	{
		y = 0;
		while (y < data->mlx_data.height)
		{
			if (ANTI_ALIASING)
				color = average_pixel(data, (*camera), (*vp), \
					(t_touple){.x = x, .y = y});
			else
			{
				(*camera).dir = get_direction(data, (*vp), x, y);
				color = trace_ray(data, (*camera), 0);
			}
			if (color != 0)
				put_pixel(x, y, color, data);
			y++;
		}
		if (x % 10 == 0 && x != 0 && x / (data->mlx_data.width / 100) < 100)
			ft_printf("%d%%\n", x / (data->mlx_data.width / 100));
		x ++;
	}
}
