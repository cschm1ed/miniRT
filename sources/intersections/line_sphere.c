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

static double	get_t(double a, double b, double discriminant);

int	intersection_line_sphere(void *object, t_line line, t_intersect *inter)
{
	t_vector	oc;
	t_sphere	*sphere;
	t_vector	abc;
	double		t;

	sphere = (t_sphere *) object;
	line.direction = _divide(line.direction, _len(line.direction));
	oc = _subtract(line.base, sphere->center);
	abc.x = _dot(line.direction, line.direction);
	abc.y = 2 * _dot(oc, line.direction);
	abc.z = _dot(oc, oc) - pow(sphere->diameter / 2, 2);
	if (pow(abc.y, 2) - (4 * abc.x * abc.z) >= 0)
	{
		t = get_t(abc.x, abc.y, pow(abc.y, 2) - (4 * abc.x * abc.z));
		inter->point = _add(_multiply(line.direction, t), line.base);
		inter->normal = _subtract(inter->point, sphere->center);
		inter->normal = _divide(inter->normal, _len(inter->normal));
		return (TRUE);
	}
	return (FALSE);
}

static double	get_t(double a, double b, double discriminant)
{
	double	t1;
	double	t2;

	t1 = -b;
	t1 += sqrt(discriminant);
	t1 /= 2 * a;
	t2 = -b;
	t2 -= sqrt(discriminant);
	t2 /= 2 * a;
	if (t1 < 0 && t2 < 0)
		return (FALSE);
	if (t1 < t2 && t1 > 0)
		return (t1);
	else
		return (t2);
}
