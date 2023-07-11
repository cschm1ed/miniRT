/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:23:31 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/23 11:23:31 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

//static int line_in_plane(t_plane plane, t_line line);

int intersection_line_plane(void *object, t_line line, t_vector *result)
{
	t_vector	n;
	double 		t;
	t_plane		*plane;

	plane = (t_plane*)object;
	n = plane->v1;
	line.direction = _divide(line.direction, _len(line.direction));
if (fabs(_dot(n, line.direction)) < EPSILON) // parallel
	{
		//if (line_in_plane(*plane, line) == TRUE)
		//	return (TRUE);
		return (FALSE);
	}
	t = (_dot(_subtract(plane->base, line.base), n)
			/ _dot(line.direction , n));
	if (t < 0)
		return (FALSE);
	*result = _multiply(line.direction, t);
	*result = _add(*result, line.base);
	return (TRUE);
}
