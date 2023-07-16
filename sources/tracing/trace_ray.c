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

int trace_ray(t_data *data, t_line line, int depth)
{
    t_intersect inters;
	t_line		bounce;
	int 		color;

	if (depth == MAX_DEPTH)
		return (0);
    inters.ray = line;
	if (closest_intersection(data->scene, &inters))
	{
		bounce.base = inters.point;
		bounce.direction = (t_vector){0,0,0};
		color = calculate_color(data, inters, depth);
		return (color);
	}
	return (0);
}

int closest_intersection(t_scene *scene, t_intersect *intersect)
{
	t_intersect int_tmp;
	t_list  	*objs;
	double  	len_min;
	double		len_tmp;
	int 		hit;

    hit = FALSE;
    objs = scene->all_objs;
	int_tmp.ray = intersect->ray;
    while (objs)
    {
        if (objs->intersection(objs->content, intersect->ray, &int_tmp))
        {
            len_tmp = _len(_subtract(int_tmp.point, intersect->ray.base));
            if (!hit || len_tmp < len_min)
            {
                intersect->obj = objs;
                intersect->point = int_tmp.point;
                intersect->normal = int_tmp.normal;
                len_min = len_tmp;
                hit = TRUE;
            }
        }
        objs = objs->next;
    }
	if (hit)
		return (TRUE);
    return (FALSE);
}

t_vector	_reflect(t_vector inc, t_vector normal)
{
	float	dot;
	t_vector 	mul;

	dot = _dot(normal, inc);
	mul = _multiply(normal, dot);
	mul = _multiply(mul, 2.0f);
	return (_subtract(inc, mul));
}
