/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:23:10 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/20 13:29:25 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	trace_ray(t_data *data, t_line line, int depth)
{
	t_intersect	inters;
	t_line		bounce;
	int			color;

	if (depth == MAX_DEPTH)
		return (0);
	inters.ray = line;
	if (closest_intersection(data->scene, &inters))
	{
		bounce.base = inters.point;
		bounce.direction = (t_vector){0, 0, 0};
		color = calculate_color(data, inters, depth);
		return (color);
	}
	return (0);
}

int	closest_intersection(t_scene *scene, t_intersect *intersect)
{
	t_intersect	int_tmp;
	t_list		*objs;
	t_touple	len;
	int			hit;

	hit = FALSE;
	objs = scene->all_objs;
	int_tmp.ray = intersect->ray;
	while (objs)
	{
		if (objs->intersection(objs->content, intersect->ray, &int_tmp))
		{
			len.x = _len(_subtract(int_tmp.point, intersect->ray.base));
			if (!hit || len.x < len.y)
			{
				intersect->obj = objs;
				intersect->point = int_tmp.point;
				intersect->normal = int_tmp.normal;
				len.y = len.x;
				hit = TRUE;
			}
		}
		objs = objs->next;
	}
	return (hit);
}

t_vector	_reflect(t_vector inc, t_vector normal)
{
	float		dot;
	t_vector	mul;

	dot = _dot(normal, inc);
	mul = _multiply(normal, dot);
	mul = _multiply(mul, 2.0f);
	return (_subtract(inc, mul));
}

inline int	is_obscured(t_scene *scene, t_intersect intersect)
{
	t_vector	direction;
	t_intersect	inters;
	double		distance;

	direction = _subtract(((t_light_source *)scene->light_lst->content) \
							->center, intersect.point);
	distance = _len(direction);
	intersect.point = _add(intersect.point, \
							_multiply(_divide(direction, distance), 0.0001f));
	inters.ray.base = intersect.point;
	inters.ray.direction = direction;
	if (closest_intersection(scene, &inters))
	{
		if (_len(_subtract(inters.point, intersect.point)) + 0.0001f < distance)
			return (TRUE);
	}
	return (FALSE);
}

inline t_vector	get_reflection(t_data *data, t_intersect inter, int depth)
{
	t_vector	reflected;
	t_line		reflection;
	t_vector	dir_norm;

	reflection.base = inter.point;
	reflection.direction = _reflect(inter.ray.direction, inter.normal);
	dir_norm = _divide(reflection.direction, _len(reflection.direction));
	reflection.base = _add(reflection.base, _multiply(dir_norm, 0.0001f));
	reflected = colour_to_vector(trace_ray(data, reflection, depth + 1));
	reflected = _divide(reflected, 255);
	return (_multiply(reflected, inter.obj->reflective));
}
