/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 09:14:49 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/03 09:23:20 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int calculate_color(t_data *data, t_intersect inter)
{
	t_vector	intensity;
	int 		obj_col;
	int 		color;

	obj_col = (*(int *)((inter.obj->content)));
	intensity = get_intensity(data->scene, inter);
	color = ambient_illumination(inter.obj, data->scene);
	color = c_add(color, c_multiply(obj_col, intensity));
	return (color);
}

int ambient_illumination(void *obj, t_scene *scene)
{
	t_vector colobj;
	t_vector colamb;
	t_vector out;

	colobj = colour_to_vector(*((int*)obj));
	colobj = _divide(colobj, 255);
	colamb = colour_to_vector(scene->ambient_light->colour);
	colamb = _divide(colamb, 255);
	colamb = _multiply(colamb, scene->ambient_light->light_ratio);
	out = (t_vector){colobj.x * colamb.x, colobj.y * colamb.y, colobj.z *colamb.z};
	return (vector_to_colour(_multiply(out, 255)));
}

t_vector get_intensity(t_scene *scene, t_intersect inter)
{
	t_vector	out;
	t_vector 	light;
	t_vector 	direction;
	double 		distance;

	light = ((t_light_source*)scene->light_lst->content)->center;
	direction = _subtract(light, inter.point);
	distance = _len(direction);
	inter.point = _add(inter.point, _multiply(direction, 0.00001f));
	if (is_obscured(scene, distance, inter.point) == TRUE)
	{
		return ((t_vector){0,0,0});
	}
	distance /= 2;
	out = colour_to_vector(((t_light_source*)scene->light_lst->content)->colour);
	return (_multiply(out, 1 / pow(distance, 2)));
}

int is_obscured(t_scene *scene, double distance, t_vector intersect)
{
	t_vector    direction;
	t_intersect inters;

	direction = _subtract(((t_light_source*)scene->light_lst->content)->center, intersect);
	inters.ray = (t_line){intersect, direction};
	scene->all_last_tmp->next = NULL;
	if (closest_intersection(scene, &inters))
	{
		if (_len(_subtract(inters.point, intersect)) + 0.0001f < distance)
			return (ft_lstadd_back(&scene->all_objs, scene->plane_lst), TRUE);
	}
	ft_lstadd_back(&scene->all_objs, scene->plane_lst);
	return (FALSE);
}
