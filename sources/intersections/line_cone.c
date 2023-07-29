/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_cone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:53:13 by estruckm          #+#    #+#             */
/*   Updated: 2023/07/28 19:52:10 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int quadratic_equation(double a, double b, double c)
{
	double result_1;
	double result_2;

	result_1 = ((-1 * b) + sqrt((pow(b, 2) - 4 * a * c))) / 2 * a;
	result_2 = ((-1 * b) - sqrt((pow(b, 2) - 4 * a * c))) / 2 * a;
	if (result_1 > result_2)
		return (result_2);
	else
		return (result_1);
}

int cap_intersection(t_cone cone, t_vector ray_direction, t_vector point)
{
	t_vector intersect;
	double t;
	double distance;

	if (fabs(_dot(cone.center, ray_direction)) < EPSILON)
		return (FALSE);
	t = (_dot(_subtract(cone.center, ray_direction), cone.center)
			/ _dot(ray_direction, cone.center));
	if (t < 0)
		return (FALSE);
	intersect = _add(point, _multiply(ray_direction, t));
	distance = _len(_subtract(cone.center, intersect));
	if (distance <=  cone.radius)
		return (TRUE);
	return (FALSE);
}

t_vector cone_surface_normal(t_cone cone, t_intersect *inter)
{
	double len_q;
	t_vector q;
	t_vector axis_direction;
	t_vector surface_normal;

	axis_direction = _multiply(cone.axis_direction, -1);

	len_q = cone.cos_angle * _len(_subtract(cone.apex, inter->point));
	q = _add(cone.apex, _multiply(axis_direction, len_q));
	surface_normal = _subtract(inter->point, q);
	return (surface_normal);
}

int line_cone(void *object, t_line line, t_intersect *inter)
{
	t_vector	h_n;
	t_vector v;
	t_vector w;
	t_cone cone;
	// t_vector p_apex;
	// t_vector axis_direction;
	// t_vector co;

	double m;
	double t;
	double a;
	double b;
	double c;
	// double h;
	double condition;

	cone = *((t_cone*)object);

	h_n = _divide(_subtract(cone.center, cone.apex), _len(_subtract(cone.center, cone.apex)));
	m = pow(cone.radius, 2) / pow(_len(_subtract(cone.center, cone.apex)), 2);
	v = line.direction;
	w = _subtract(line.base, cone.apex);
	// w = _multiply(_subtract(line.base, cone.apex), -1);
	// co = _subtract(line.base, cone.apex);

	a = _dot(v, v) - (m * pow(_dot(v, h_n), 2)) - pow(_dot(v, h_n), 2);
	b = 2 * (_dot(v, w) - (m * _dot(v, h_n) * _dot(w, h_n)) - (_dot(v, h_n) * _dot(w, h_n)));
	c = _dot(w, w) - (m * pow(_dot(w, h_n), 2)) - pow(_dot(w, h_n), 2);
	// a = _dot(v, w) * _dot(v, w) - (cone.opening_angle * cone.opening_angle);
	// b = 2 * _dot(v, w) * _dot(co, w) - _dot(v, co) * (cone.opening_angle / 2* cone.opening_angle / 2);
	// c = _dot(co, w) * _dot(co, w) - _dot(co, co) * (cone.opening_angle / 2 * cone.opening_angle / 2);
	condition = pow(b, 2) - (4 * a * c);

	if (condition > 0)
	{
		t = quadratic_equation(a, b, c);
		inter->point = _add(line.base, _multiply(line.direction, t));
		// axis_direction = _subtract(cone.apex, cone.center);
		// p_apex = _subtract(inter->point, cone.apex);
		// h = _dot(p_apex, cone.axis_direction);
		// if (h < 0 || h > cone.height)
		// 	return (FALSE);
		if (0 <= _dot(_subtract(inter->point, cone.apex), h_n) &&  _dot(_subtract(inter->point, cone.apex), h_n) <= _len(_subtract(cone.center, cone.apex)))
		{
			// printf("hit surface\n");
			inter->normal = cone_surface_normal(cone, inter);
			return (TRUE);
		}
		if ( _dot(_subtract(inter->point, cone.apex), h_n) > _len(_subtract(cone.center, cone.apex)))
		{
			if (cap_intersection(cone, line.direction, inter->point) == TRUE)
			{
				// printf("hit cap\n");
				inter->normal = _multiply(cone.axis_direction, -1);
				return (TRUE);
			}
			return (FALSE);
		}
	}
	return (FALSE);
}
