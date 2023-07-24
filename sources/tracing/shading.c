/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 09:14:49 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/24 15:33:51 by estruckm         ###   ########.fr       */
=======
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 09:14:49 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/20 13:25:00 by cschmied         ###   ########.fr       */
>>>>>>> 753b5c6ab4409e6c285934c917f3e61ab75ba2a8
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static t_vector	ambient_illumination(t_list *obj, t_ambient_light *amb);
static t_vector	get_diffuse(t_scene *scene, t_intersect inter);
static t_vector	get_specular(t_light_source lightSource, t_intersect inter);
static inline double	get_intensity(t_list *light_sources, t_vector inter);

int	calculate_color(t_data *data, t_intersect inter, int depth)
{
	t_vector	colour;
	double		intensity;

	colour = (t_vector){0, 0, 0};
	if (inter.obj->reflective != 1)
// 		colour = _add(colour, ambient_illumination(inter.obj, data->scene->ambient_light));
// //	colour = _add(colour, get_reflection(data, inter, depth));
// 	if (is_obscured(data->scene, inter))
// 		return (vector_to_colour(_multiply(colour, 255)));
// 	intensity = get_intensity(data->scene->light_lst, inter.point);
// //	colour = _add(colour, _multiply(get_diffuse(data->scene, inter), intensity));
// //	colour = _add(colour, _multiply(get_specular(*((t_light_source*)data->scene->light_lst->content), inter), intensity));
// 	colour = (t_vector){fmin(colour.x, 1), fmin(colour.y, 1), fmin(colour.z , 1)};
	if (inter.obj->reflective != 1)
		colour = _add(colour, ambient_illumination(inter.obj, \
			data->scene->ambient_light));
	colour = _add(colour, get_reflection(data, inter, depth));
	if (is_obscured(data->scene, inter))
		return (vector_to_colour(_multiply(colour, 255)));
	intensity = get_intensity(data->scene->light_lst, inter.point);
	colour = _add(colour, _multiply(get_diffuse(data->scene, inter), \
				intensity));
	colour = _add(colour, _multiply(get_specular(*((t_light_source *) \
					data->scene->light_lst->content), inter), intensity));
	colour = (t_vector){.x = fmin(colour.x, 1), \
				.y = fmin(colour.y, 1), .z = fmin(colour.z, 1)};
	return (vector_to_colour(_multiply(colour, 255)));
}

static t_vector	get_specular(t_light_source lightSource, t_intersect inter)
{
	double		specular;
	t_vector	ref_dir;
	t_vector	inc_dir;
	t_vector	direction;
	t_vector	colour;

	direction = _subtract(lightSource.center, inter.point);
	inc_dir = _divide(inter.ray.direction, _len(inter.ray.direction));
	ref_dir = _reflect(_multiply(direction, 1), \
						inter.normal);
	ref_dir = _divide(ref_dir, _len(ref_dir));
	colour = _multiply(_divide(colour_to_vector(lightSource.colour), 255), \
						lightSource.light_ratio);
	specular = pow(fmax(_dot(inc_dir, ref_dir), 0), SPECULAR_N) \
						* inter.obj->specular;
	return (_multiply(colour, specular));
}

static inline t_vector	get_diffuse(t_scene *scene, t_intersect inter)
{
	double		diffuse;
	t_vector	normal;
	t_vector	direction;
	t_vector	out;

	direction = _subtract(((t_light_source *) \
						scene->light_lst->content)->center, inter.point);
	normal = inter.normal;
	normal = _divide(normal, _len(normal));
	diffuse = fmax(_dot(normal, _divide(direction, _len(direction))), 0.0f);
	diffuse *= inter.obj->diffuse;
	out = _multiply_element_wise(inter.obj->get_colour(inter.obj), \
						scene->light_lst->get_colour(scene->light_lst));
	out = _multiply(out, diffuse);
	return (out);
}

static inline double	get_intensity(t_list *ls, t_vector inter)
{
	double	distance;

	distance = _len(_subtract(((t_light_source *)ls->content) \
							->center, inter));
	distance *= DISTANCE_FACTOR;
	return (fmin(1 / pow(distance, 2) * 1.7f, 1));
}

static inline t_vector	ambient_illumination(t_list *obj, t_ambient_light *amb)
{
	t_vector	ambient;

	ambient = _divide(colour_to_vector(amb->colour), 255);
	ambient = _multiply(ambient, amb->light_ratio);
	ambient = _multiply_element_wise(obj->get_colour(obj), ambient);
	return (ambient);
}
