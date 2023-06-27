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
	t_list		*objs;
	t_vector 	intersection;
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
			len_tmp = vector_len(substract(intersection, line.base));
			if (!hit || len_tmp < len_min)
			{
				color = trgb(0, 250, 50, 100);
				len_min = len_tmp;
				hit = TRUE;
			}
		}
		objs = objs->next;
	}
	return (color + trace_ray(data, (t_line){intersection, {0, 0, 0}}, depth + 1));
}
