/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:58:04 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/09 10:58:04 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

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
					   inter.obj->surface_normal(inter.obj, inter.point));
	ref_dir = _divide(ref_dir, _len(ref_dir));
	specular = pow(fmax(_dot(inc_dir, ref_dir), 0), 120) / SPECULAR;
	colour = _multiply(_divide(colour_to_vector(lightSource.colour), 255), lightSource.light_ratio);
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
	normal = inter.obj->surface_normal(inter.obj, inter.point);
	normal = _divide(normal, _len(normal));
	diffuse = fmax(_dot(normal, _divide(direction, _len(direction))), 0.0f);
	diffuse *= DIFFUSE;
	out = _multiply_element_wise(inter.obj->get_colour(inter.obj),
								 scene->light_lst->get_colour(scene->light_lst));
	out = _multiply(out, diffuse);
	return (out);
}
