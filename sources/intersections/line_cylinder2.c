/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_cylinder2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:15:45 by estruckm          #+#    #+#             */
/*   Updated: 2023/07/16 18:15:45 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

//t_vector normal_tube_cylinder(t_vector point, t_cylindner cylindner)
//{
//	t_plane	pl;
//	t_line 	ln;
//	t_vector q;
//	t_vector n;
//	double 		t;
//
//	pl.base = point;
//	pl.v1 = cylindner.axis_direction;
//	ln.base = cylindner.center;
//	ln.direction  = cylindner.axis_direction;
//
//	t = (_dot(_subtract(pl.base, ln.base), pl.v1)
//		 / _dot(ln.direction, pl.v1));
//
//	q = _add(cylindner.center, _multiply(ln.direction, t));
//	n = _subtract(point, q);
//	return (_divide(n, _len(n)));
//}

int line_cylindner(void *object, t_line line, t_intersect *inter)
{

	t_vector apex;
	t_vector cap_center;
	t_cylindner cylindner;
	t_vector cap_normal;
	t_vector point;
	double t;

	t_vector h_normal;
	t_vector h;
	t_vector w;
	t_vector v;

	double root_term;
	double check;
	double t1;
	double t2;
	double a;
	double b;
	double c;
	double check2;

	cylindner = *((t_cylindner*)object);
	apex = _add(cylindner.center, _multiply(cylindner.axis_direction, cylindner.height));
	check2 = 1;

	if (_len(_subtract(apex, line.base)) < _len(_subtract(cylindner.center, line.base)))
	{
		cap_center = apex;
		cap_normal = cylindner.axis_direction;
	}
	else
	{
		cap_center = cylindner.center;
		cap_normal = _multiply(cylindner.axis_direction, -1);
	}
	t = _dot(_subtract(cap_center, line.base), cap_normal) / _dot(line.direction, cap_normal);
	if (t != 0)
	{
		point = _add(line.base, _multiply(line.direction, t));
		if (_len(_subtract(point, cap_center)) <= cylindner.diameter / 2)
		{
			check2 = 0;
			inter->point = point;
			inter->normal = cap_normal;
			return (TRUE);
		}
	}
	if (check2 == 1)
	{
		h = _multiply(_subtract(apex, cylindner.center), 2);
		h_normal = _divide(h, _len(h));
		w = _subtract(line.base, cylindner.center);
		v = _divide(line.direction, _len(line.direction));

		a = _dot(v, v) - pow(_dot(v, h_normal), 2);
		b = 2 * (_dot(v, w) - _dot(v, h_normal) * _dot(w, h_normal));
		c = _dot(w, w) - pow(_dot(w, h_normal), 2) - pow(cylindner.diameter / 2, 2);

		root_term = pow(b, 2) - (4 * a * c);
		if (root_term > 0)
		{
			t1 = (-b + sqrt(root_term)) / (2 * a);
			t2 = (-b - sqrt(root_term)) / (2 * a);
			if (t1 < 0 && t2 < 0)
				return (FALSE);
			if (t1 < t2 && t1 > 0)
				t = t1;
			else
				t = t2;
			point = _add(line.base, _multiply(v, t));
			check = _dot(_subtract(point, cylindner.center), h);

			if (0 <= check && check <= _len(h))
			{
				inter->point = point;
				inter->normal = normal_tube_cylinder(inter->point, cylindner);
				return (TRUE);
			}
		}
	}
	return (FALSE);
}