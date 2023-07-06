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

	color = 0;
	obj_col = (*(int *)((inter.obj->content)));
	intensity = get_intensity(data->scene, inter);
	if (data->scene->ambient_light)
		color = ambient_illumination(inter.obj, data->scene);
	color = c_add(color, c_multiply(obj_col, intensity));
	return (color);
}

int ambient_illumination(void *obj, t_scene *scene)
{
	t_vector colobj;
	t_vector colamb;
	t_vector out;

	colobj = colour_to_vector(*((int*)((t_list*)obj)->content));
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
	out = colour_to_vector(((t_light_source*)scene->light_lst->content)->colour);
	out = _divide(out, 255);

	double		diffuse;
	t_vector 	normal;

	normal = inter.obj->surface_normal(inter.obj, inter.point);
	normal = _divide(normal, _len(normal));
	diffuse = fmax(_dot(normal, _divide(direction, _len(direction))), 0.0f);


	double		specular;
	t_vector 	ref_dir;
	t_vector 	inc_dir;

	inc_dir = _divide(inter.ray.direction, _len(inter.ray.direction));
	ref_dir = _reflect(_multiply(direction, 1), normal);
	ref_dir = _divide(ref_dir, _len(ref_dir));
	specular = pow(fmax(_dot(inc_dir, ref_dir), 0), 20);

	distance /= 10;
	out = _multiply(out, diffuse * 0.3 + specular * 0.6);

	out = _multiply(out, 1 / pow(distance, 2));
	out = (t_vector){fmin(out.x, 1), fmin(out.y, 1), fmin(out.z, 1)};

	return (_multiply(out, 255));
}

t_vector get_diffuse()
{

}

t_vector get_specular()
{
	
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
