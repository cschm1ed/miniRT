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

int intersection_line_sphere(t_sphere sphere, t_line line, t_vector *result)
{
	t_vector	oc;
	float 		t1;
	float 		t2;
	float 		a;
	float 		b;
	float 		c;
	float 		discriminant;

	oc = substract(line.base, sphere.center);
	a = dot(line.direction, line.direction);
	b = 2 * dot(oc, line.direction);
	c = dot(oc, oc) - pow(sphere.diameter, 2);
	discriminant = b * b - (4 * a * c);
	if (discriminant > 0)
	{
		t1 = -b;
		t1 += (float)sqrt(discriminant);
		t1 /= (float)2 * a;
		t2 = -b;
		t2 -= sqrt(discriminant);
		t2 /= 2 * a;
		if (t1 < 0 && t2 < 0)
			return (FALSE);
		if (vector_len(vector_add(vector_x_scalar(line.direction, t1), line.base)) <
				vector_len(vector_add(vector_x_scalar(line.direction, t2), line.base)))
			*result = vector_add(vector_x_scalar(line.direction, t1), line.base);
		else
			*result = vector_add(vector_x_scalar(line.direction, t2), line.base);
		return (TRUE);
	}
	return (FALSE);
}
