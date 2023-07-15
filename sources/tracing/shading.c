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

t_vector ambient_illumination(t_list *obj, t_ambient_light *ambientLight);
t_vector get_diffuse(t_scene *scene, t_intersect inter);
t_vector get_specular(t_light_source lightSource, t_intersect inter);

int calculate_color(t_data *data, t_intersect inter, int depth)
{
	t_vector 	colour;
    double      intensity;

	colour = (t_vector){0,0,0};
    if (inter.obj->reflective != 1)
	    colour = _add(colour, ambient_illumination(inter.obj, data->scene->ambient_light));
    colour = _add(colour, get_reflection(data, inter, depth));
    if (is_obscured(data->scene, inter.point))
        return (vector_to_colour(_multiply(colour, 255)));
    intensity = get_intensity(data->scene->light_lst, inter.point);
    colour = _add(colour, _multiply(get_diffuse(data->scene, inter), intensity));
    colour = _add(colour, _multiply(get_specular(*((t_light_source*)data->scene->light_lst->content), inter), intensity));
	colour = (t_vector){fmin(colour.x, 1), fmin(colour.y, 1), fmin(colour.z , 1)};
	return (vector_to_colour(_multiply(colour, 255)));
    (void)depth;
}

t_vector get_reflection(t_data *data, t_intersect inter, int depth)
{
    t_vector    reflected;
    t_line      reflection;
    t_vector    dir_norm;

    reflection.base = inter.point;
    reflection.direction = _reflect(inter.ray.direction, inter.normal);
    dir_norm = _divide(reflection.direction, _len(reflection.direction));
    reflection.base = _add(reflection.base, _multiply(dir_norm, 0.0001f));
    reflected = colour_to_vector(trace_ray(data, reflection, depth + 1));
    reflected = _divide(reflected, 255);
    return (_multiply(reflected, inter.obj->reflective));
}

t_vector get_specular(t_light_source lightSource, t_intersect inter)
{
	double		specular;
	t_vector 	ref_dir;
	t_vector 	inc_dir;
	t_vector 	direction;
	t_vector 	colour;

	direction = _subtract(lightSource.center, inter.point);
	inc_dir = _divide(inter.ray.direction, _len(inter.ray.direction));
	ref_dir = _reflect(_multiply(direction, 1),
		inter.normal);
	ref_dir = _divide(ref_dir, _len(ref_dir));
	colour = _multiply(_divide(colour_to_vector(lightSource.colour), 255), lightSource.light_ratio);
	specular = pow(fmax(_dot(inc_dir, ref_dir), 0), SPECULAR_N) * inter.obj->specular;
	return (_multiply(colour, specular));
}

t_vector get_diffuse(t_scene *scene, t_intersect inter)
{
	double		diffuse;
	t_vector 	normal;
	t_vector 	direction;
	t_vector 	out;

	direction = _subtract(((t_light_source*)
			scene->light_lst->content)->center, inter.point);
	normal = inter.normal;
	normal = _divide(normal, _len(normal));
	diffuse = fmax(_dot(normal, _divide(direction, _len(direction))), 0.0f);
	diffuse *= inter.obj->diffuse;
	out = _multiply_element_wise(inter.obj->get_colour(inter.obj),
		scene->light_lst->get_colour(scene->light_lst));
	out = _multiply(out, diffuse);
	return (out);
}

double	get_intensity(t_list *light_sources, t_vector intersection)
{
	double distance;

	distance = _len(_subtract(((t_light_source*)light_sources->content)->center, intersection));
	distance *= DISTANCE_FACTOR;
	return (fmin(1 / pow(distance, 2) * 1.7f, 1));
}

t_vector ambient_illumination(t_list *obj, t_ambient_light *ambientLight)
{
	t_vector ambient;

	ambient = _divide(colour_to_vector(ambientLight->colour), 255);
	ambient = _multiply(ambient, ambientLight->light_ratio);
	ambient = _multiply_element_wise(obj->get_colour(obj), ambient);
	return (ambient);
}

int is_obscured(t_scene *scene, t_vector intersect)
{
	t_vector    direction;
	t_intersect inters;
	double 		distance;

	direction = _subtract(((t_light_source*)scene->light_lst->content)->center, intersect);
	distance = _len(direction);
	intersect = _add(intersect, _multiply(_divide(direction, distance), 0.0001f));
	inters.ray = (t_line){intersect, direction};
	if (closest_intersection(scene, &inters))
	{
		if (_len(_subtract(inters.point, intersect)) + 0.0001f < distance)
			return (TRUE);
	}
	return (FALSE);
}
