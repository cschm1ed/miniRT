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

static t_vector calculate_intensity(t_scene *scene, t_vector intersect, t_line inc, void *obj);
static	int ambient_illumination(void *obj, t_scene *scene);

int trace_ray(t_data *data, t_line line, int depth)
{
	t_list		*objs;
	t_vector 	intersection;
	t_vector 	intensity;
	t_vector 	intersection_tmp;
	t_list		*obj_tmp;
	double 		len_min;
	double 		len_tmp;
	int 		color;
	int 		hit;

	if (depth == MAX_DEPTH)
		return (0);
	hit = 0;
	len_min = 0;
	color = 0;
	intersection = (t_vector){0, 0, 0};
	objs = data->scene->all_objs;
	while (objs)
	{
		if (objs->intersection(objs->content, line, &intersection))
		{
			len_tmp = vector_len(_subtract(intersection, line.base));
			if (!hit || len_tmp < len_min)
			{
				intersection_tmp = intersection;
				obj_tmp = objs;
				len_min = len_tmp;
				hit = TRUE;
			}
		}
		objs = objs->next;
	}
	if (hit)
	{
		intensity = calculate_intensity(data->scene, intersection_tmp, line, obj_tmp);
		color = ambient_illumination(obj_tmp, data->scene);
		color = colour_add(color, colour_x_intensity((*(int*)((obj_tmp->content))), intensity));
		return (color + trace_ray(data, (t_line){intersection_tmp, {0, 0, 0}}, depth + 1));
	}
	return (0);
}

static	int ambient_illumination(void *obj, t_scene *scene)
{
	t_vector colobj;
	t_vector colambient;
	t_vector out;

	colobj = colour_to_vector(*((int*)obj));
	colobj = _divide(colobj, 255);
	colambient = colour_to_vector(scene->ambient_light->colour);
	colambient = _divide(colambient, 255);
	colambient = _multiply(colambient, scene->ambient_light->light_ratio);
	out = (t_vector){colobj.x * colambient.x, colobj.y * colambient.y, colobj.z *colambient.z};
	return (vector_to_colour(_multiply(out, 255)));
}

static t_vector calculate_intensity(t_scene *scene, t_vector intersect, t_line inc, void *obj)
{
	t_vector	out;
	t_vector 	light;
	t_vector 	direction;
	t_list		*objs;
	double 		distance;

	objs = scene->all_objs;
	light = ((t_light_source *)scene->light_lst->content)->center;
	direction = _subtract(light, intersect);
	intersect = _add(intersect, vector_x_scalar(direction, 0.00001f));
	distance = vector_len(direction);
	while (objs)
	{
		if (objs->intersection(objs->content, (t_line){intersect, direction}, &out))
			if (vector_len(out) + 0.00001f < distance)
				return ((t_vector){0,0,0});
		objs = objs->next;
	}
	out = colour_to_vector(((t_light_source*)scene->light_lst->content)->colour);
	distance /= 2;
	(void)inc;
	(void)obj;
	// Calculate diffuse intensity
	out = colour_to_vector(((t_light_source*)scene->light_lst->content)->colour);
	return (vector_x_scalar(out, 1 / pow(distance, 2)));
}
