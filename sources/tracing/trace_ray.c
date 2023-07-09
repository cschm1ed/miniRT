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
		if (inters.obj->mirror == TRUE)
		{
			printf("test1\n");
			bounce.direction = _reflect(inters.ray.direction,
					inters.obj->surface_normal(inters.obj, inters.point));
			printf("test2\n");
			color = trace_ray(data, bounce, MAX_DEPTH - 1);
		}
		else
			color = calculate_color(data, inters);
		//color += trace_ray(data, bounce, depth + 1);
		return (color);
	}
	return (0);
}

int closest_intersection(t_scene *scene, t_intersect *intersect)
{
	t_vector	int_tmp;
	t_list  	*objs;
	double  	len_min;
	double		len_tmp;
	int 		hit;

    hit = FALSE;
    objs = scene->all_objs;
    while (objs)
    {
        if (objs->intersection(objs->content, intersect->ray, &int_tmp))
        {
            len_tmp = _len(_subtract(int_tmp, intersect->ray.base));
            if (!hit || len_tmp < len_min)
            {
                intersect->point = int_tmp;
                intersect->obj = objs;
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
