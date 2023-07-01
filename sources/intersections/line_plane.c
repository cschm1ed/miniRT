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

static int line_in_plane(t_plane plane, t_line line);

int intersection_line_plane(void *object, t_line line, t_vector *result)
{
	t_vector	n;
	double 		t;
	t_plane		*plane;

	plane = (t_plane*)object;
	n = _cross(plane->v1, plane->v2);
	if (fabs(_dot(n, line.direction)) < EPSILON) // parallel
	{
		if (line_in_plane(*plane, line) == TRUE)
			return (TRUE);
		return (FALSE);
	}
	t = (_dot(_subtract(plane->base, line.base), n)
			/ _dot(line.direction , n));
	if (t < 0)
		return (FALSE);
	*result = vector_x_scalar(line.direction, t);
	*result = _add(*result, line.base);
	return (TRUE);
}

int line_in_plane(t_plane plane, t_line line)
{
	t_vector	n;

	n = _cross(plane.v1, plane.v2);
	if (_dot(n, line.direction) != 0)
		return (FALSE);
	if (_dot(line.base, n) == _dot(plane.base, n))
		return (TRUE);
	return (FALSE);
}
