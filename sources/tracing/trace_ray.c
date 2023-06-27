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

static t_vector calculate_intensity(t_scene *scene, void *obj, t_vector intersect, t_line inc);

int trace_ray(t_data *data, t_line line, int depth)
{
	t_list		*objs;
	t_vector 	intersection;
	t_vector 	intensity;
	float 		len_min;
	float 		len_tmp;
	int 		color;
	int 		hit;

	hit = 0;
	len_min = 0;
	color = 0;
	intersection = (t_vector){0, 0, 0};
	if (depth == MAX_DEPTH)
		return (0);
	objs = data->scene->all_objs;
	while (objs)
	{
		if (objs->intersection(objs->content, line, &intersection))
		{
			len_tmp = vector_len(subtract(intersection, line.base));
			if (!hit || len_tmp < len_min)
			{
				intensity = calculate_intensity(data->scene, objs, intersection, line);
				color = colour_x_intensity((*(int*)((objs->content))), intensity);
				len_min = len_tmp;
				hit = TRUE;
			}
		}
		objs = objs->next;
	}
	return (color + trace_ray(data, (t_line){intersection, {0, 0, 0}}, depth + 1));
}

static t_vector calculate_intensity(t_scene *scene, void *obj, t_vector intersect, t_line inc)
{
	t_vector	out;
	float 		distance;

	out = (t_vector){255, 255, 255};
	distance = vector_len(subtract(intersect, inc.base));
	(void)scene; // add actual light
	(void)obj; // add actual camera
	return (vector_x_scalar(out, 1 / distance));
}
