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

int	average_pixel(t_data *data, t_line camera, t_plane vp, t_touple pos)
{
	int	c1;
	int	c2;
	int	c3;
	int	c4;

	camera.dir = get_direction(data, vp, pos.x + 0.25f, pos.y);
	c1 = trace_ray(data, camera, 0);
	camera.dir = get_direction(data, vp, pos.x + 0.75f, pos.y);
	c2 = trace_ray(data, camera, 0);
	camera.dir = get_direction(data, vp, pos.x + 0.25f, pos.y + 0.75f);
	c3 = trace_ray(data, camera, 0);
	camera.dir = get_direction(data, vp, pos.x + 0.75f, pos.y + 0.75f);
	c4 = trace_ray(data, camera, 0);
	return (average_colours(c1, c2, c3, c4));
}

int	average_colours(int c1, int c2, int c3, int c4)
{
	t_vector	col1;
	t_vector	col2;
	t_vector	col3;
	t_vector	col4;

	col1 = colour_to_vector(c1);
	col2 = colour_to_vector(c2);
	col3 = colour_to_vector(c3);
	col4 = colour_to_vector(c4);
	col1.x = (col1.x + col2.x + col3.x + col4.x) / 4;
	col1.y = (col1.y + col2.y + col3.y + col4.y) / 4;
	col1.z = (col1.z + col2.z + col3.z + col4.z) / 4;
	return (get_colour(0, col1.x, col1.y, col1.z));
}

t_vector	get_direction(t_data *data, t_plane vp, double x, double y)
{
	t_vector	start;
	double		width;
	double		height;

	width = 2 * tanf((data->scene->camera->degrees / 2) * M_PI / 180);
	height = width / (WIDTH / HEIGHT);
	start = _add(vp.base, _multiply(vp.v2, height / 2));
	start = _add(start, _multiply(vp.v1, width / 2));
	start = _add(start, _multiply(vp.v2, -y * (height / HEIGHT)));
	start = _add(start, _multiply(vp.v1, -x * (width / WIDTH)));
	return (_subtract(start, data->scene->camera->center));
}
