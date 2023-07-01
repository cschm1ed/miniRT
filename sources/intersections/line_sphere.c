/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 08:29:39 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/22 08:29:39 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int intersection_line_sphere(void *object, t_line line, t_vector *result)
{
	t_vector	oc;
	t_sphere	*sphere;
	double 		t1;
	double 		t2;
	double 		a;
	double 		b;
	double 		c;
	double 		discriminant;

	sphere = (t_sphere*)object;
	oc = _subtract(line.base, sphere->center);
	a = _dot(line.direction, line.direction);
	b = 2 * _dot(oc, line.direction);
	c = _dot(oc, oc) - pow(sphere->diameter, 2);
	discriminant = b * b - (4 * a * c);
	if (discriminant > 0)
	{
		t1 = -b;
		t1 += (double)sqrt(discriminant);
		t1 /= (double)2 * a;
		t2 = -b;
		t2 -= sqrt(discriminant);
		t2 /= 2 * a;
		if (t1 < 0 && t2 < 0)
			return (FALSE);
		if (vector_len(_add(vector_x_scalar(line.direction, t1), line.base)) <
				vector_len(_add(vector_x_scalar(line.direction, t2), line.base)))
			*result = _add(vector_x_scalar(line.direction, t1), line.base);
		else
			*result = _add(vector_x_scalar(line.direction, t2), line.base);
		return (TRUE);
	}
	return (FALSE);
}
