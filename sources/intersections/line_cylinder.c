/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_cylindner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:22:18 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/23 11:22:18 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int bottom_cap_intersection(t_cylindner cylindner, t_vector ray_direction, t_vector point)
{
	t_vector intersect;
	t_vector axis_direction;
	double dot_product;
	double t;
	double distance;

	axis_direction = _multiply(cylindner.axis_direction, -1);
	dot_product = _dot(axis_direction, ray_direction);
	if (fabs(dot_product) < 0.00001)
		return (FALSE);
	t = _dot(axis_direction, _subtract(cylindner.center, point)) / dot_product;
	if (t < 0)
		return (FALSE);
	intersect = _add(point, _multiply(ray_direction, t));
	distance = _len(_subtract(cylindner.center, intersect));
	if (distance <= cylindner.diameter / 2)
		return (TRUE);
	return (FALSE);
}

int top_cap_intersection(t_cylindner cylindner, t_vector ray_direction, t_vector point)
{
	t_vector intersect;
	t_vector apex;
	double dot_product;
	double t;
	double distance;

	apex = _add(cylindner.center, _multiply(cylindner.axis_direction, cylindner.height));
	dot_product = _dot(cylindner.axis_direction, ray_direction);
	if (fabs(dot_product) < 0.00001)
		return (FALSE);
	t = _dot(cylindner.axis_direction, _subtract(apex, point)) / dot_product;
	if (t < 0)
		return (FALSE);
	intersect = _add(point, _multiply(ray_direction, t));
	distance = _len(_subtract(apex, intersect));
	if (distance <= cylindner.diameter / 2)
		return (TRUE);
	return (FALSE);
}

int line_cylindner(void *object, t_line line, t_intersect *inter)
{
	t_vector h;
	t_vector apex;
	t_vector h_normal;
	t_vector w;
	t_vector v;
	t_vector point;

	double a;
	double b;
	double c;

	double t1;
	double t2;
	double t;
	double root_term;
	double check;

	t_cylindner cylindner;

	cylindner = *((t_cylindner*)object);
	cylindner.axis_direction = _divide(cylindner.axis_direction, _len(cylindner.axis_direction));
    apex = _add(cylindner.center, _multiply(cylindner.axis_direction, cylindner.height / 2));

	h = _multiply(_subtract(apex, cylindner.center), 2);
	h_normal = _divide(h, _len(h));
	w = _subtract(line.base, cylindner.center);
	v = _divide(line.direction, _len(line.direction));

	a = _dot(v, v) - pow(_dot(v, h_normal), 2);
	b = 2 * (_dot(v, w) - _dot(v, h_normal) * _dot(w, h_normal));
	c = _dot(w, w) - pow(_dot(w, h_normal),2) - pow(cylindner.diameter / 2, 2);

	root_term = pow(b, 2) - (4 * a * c);
	if (root_term > 0)
	{
		t1 = (-b + sqrt(root_term)) / (2 * a);
		t2 = (-b - sqrt(root_term)) / (2 * a);
		if (t1 < t2 && t1 > 0)
			t = t1;
        else
            t = t2;
		point = _add(line.base, _multiply(v, t));
		check =  _dot(_subtract(point, cylindner.center), h);

		if (0 <= check && check <= _len(h) * cylindner.height)
		{
			inter->point = point;

            double      len_q;
            t_vector    q;

            len_q = sqrt(pow(_len(_subtract(point, cylindner.center)), 2) - pow(cylindner.diameter / 2, 2));
            q = _add(cylindner.center, _multiply(cylindner.axis_direction, len_q));
            inter->normal = _subtract(point, q);

			return (TRUE);
		}
		if (_len(h) < check)
		{
			if (top_cap_intersection(cylindner, line.direction, point) == TRUE)
			{
				inter->point = point;
                inter->normal = cylindner.axis_direction;
				return (TRUE);
			}
		}
        if (0 > check)
        {
            if (bottom_cap_intersection(cylindner, line.direction, point) == TRUE)
            {
                inter->point = point;
                inter->normal = _multiply(cylindner.axis_direction, -1);
                return (TRUE);
            }
        }
	}
	return (FALSE);
}


//https://nachodevblog.com/posts/ray-cylindner-intersection/
