/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:23:10 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/23 19:23:10 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static t_vector calculate_intensity(t_scene *scene, t_vector intersect, t_line inc);

int trace_ray(t_data *data, t_line line, int depth)
{
	t_list		*objs;
	t_vector 	intersection;
	t_vector 	intensity;
	double 		len_min;
	double 		len_tmp;
	int 		color;
	int 		hit;

	hit = 0;
	len_min = 0;
	color = 0;
	intersection = (t_vector){0, 0, 0};
	if (depth == MAX_DEPTH)
		return (0);
	objs = data->scene->all_objs;
	while (objs)
	{
		if (objs->intersection(objs->content, line, &intersection))
		{
			len_tmp = vector_len(_subtract(intersection, line.base));
			if (!hit || len_tmp < len_min)
			{
				intensity = calculate_intensity(data->scene, intersection, line);
				color = colour_x_intensity((*(int*)((objs->content))), intensity);
				color = colour_add(color, colour_add((*(int*)(objs->content)), ((t_ambient_light*)data->scene->ambient_light->content)->colour));
				len_min = len_tmp;
				hit = TRUE;
			}
		}
		objs = objs->next;
	}
	return (color + trace_ray(data, (t_line){intersection, {0, 0, 0}}, depth + 1));
}

static t_vector calculate_intensity(t_scene *scene, t_vector intersect, t_line inc)
{
	t_vector	out;
	t_vector 	light;
	t_vector 	direction;
	t_list		*objs;
	double 		distance;

	objs = scene-> all_objs;
	light = ((t_light_source *)scene->light_lst->content)->center;
	direction = _subtract(light, intersect);
	intersect = _add(intersect, vector_x_scalar(direction, 0.001f));
	distance = vector_len(direction);
	while (objs)
	{
		if (objs->intersection(objs->content, (t_line){intersect, direction}, &out))
			if (vector_len(out) + 0.001f < distance)
				return ((t_vector){0,0,0});
		objs = objs->next;
	}
	out = colour_to_vector(((t_light_source*)scene->light_lst->content)->colour);
	distance /= 2;
	(void)inc;
	return (vector_x_scalar(out, 1 / pow(distance, 2)));
}
