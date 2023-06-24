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
	t_list		*sphere_list;
	t_list		*plane_list;
	t_vector 	intersection;
	t_vector 	intersection_tmp;
	int 		hit;
	int 		len_min;
	int 		colour;

	len_min = 0;
	hit = 0;
	plane_list = data->scene->plane_lst;
	sphere_list = data->scene->sphere_lst;
	colour = 0;
	if (depth == MAX_DEPTH)
		return (0);
	while (sphere_list)
	{
		if (intersection_line_sphere(*((t_sphere*)(sphere_list->content)), line,
				&intersection_tmp) == TRUE)
		{
			if (vector_len(vector_substract(intersection_tmp, line.base)) < len_min || !hit)
			{
				len_min = vector_len(vector_substract(intersection_tmp, line.base));
				intersection = intersection_tmp;
				colour = (((t_sphere*)(sphere_list->content)))->colour;
				hit = TRUE;
			}
		}
		sphere_list = sphere_list->next;
	}
	while (plane_list)
	{
		if (intersection_line_plane(*((t_plane*)(plane_list->content)), line,
									 &intersection_tmp) == TRUE || !hit)
		{
			if (vector_len(vector_substract(intersection_tmp, line.base)) < len_min)
			{
				len_min = vector_len(vector_substract(intersection_tmp, line.base));
				intersection = intersection_tmp;
				colour = (((t_plane*)(plane_list->content)))->colour;
				hit = TRUE;
			}
		}
		plane_list = plane_list->next;
	}
	return (colour + trace_ray(data, (t_line){intersection, {0}}, depth + 1));
}
