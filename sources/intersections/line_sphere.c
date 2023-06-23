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

int intersection_line_sphere(t_sphere sphere, t_line line)
{
	t_vector	oc;
	float 		a;
	float 		b;
	float 		c;

	oc = vector_substract(line.base, sphere.center);
	a = dot(line.direction, line.direction);
	b = 2 * dot(oc, line.direction);
	c = dot(oc, oc) - pow(sphere.diameter, 2);
	if (b * b - (4 * a * c) > 0)
		return (1);
	return (0);
}
