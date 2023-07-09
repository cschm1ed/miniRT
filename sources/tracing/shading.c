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
	t_vector 	colour;

	colour = (t_vector){0,0,0};
	if (is_obscured(data->scene, inter.point))
		return (vector_to_colour(_multiply(ambient_illumination(inter.obj, data->scene->ambient_light), 255)));
	colour = _add(colour, get_diffuse(data->scene, inter));
	colour = _add(colour, get_specular(*((t_light_source*)data->scene->light_lst->content), inter));
	colour = _multiply(colour, get_intensity(data->scene->light_lst, inter.point));
	colour = _add(colour, ambient_illumination(inter.obj, data->scene->ambient_light));
	colour = (t_vector){fmin(colour.x, 1), fmin(colour.y, 1), fmin(colour.z , 1)};
	return (vector_to_colour(_multiply(colour, 255)));
}

double	get_intensity(t_list *light_sources, t_vector intersection)
{
	double distance;

	distance = _len(_subtract(((t_light_source*)light_sources->content)->center, intersection));
	distance /= DISTANCE_FACTOR;
	return (1 / pow(distance, 2));
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
	scene->all_last_tmp->next = NULL;
	if (closest_intersection(scene, &inters))
	{
		if (_len(_subtract(inters.point, intersect)) + 0.0001f < distance)
			return (ft_lstadd_back(&scene->all_objs, scene->plane_lst), TRUE);
	}
	ft_lstadd_back(&scene->all_objs, scene->plane_lst);
	return (FALSE);
}
