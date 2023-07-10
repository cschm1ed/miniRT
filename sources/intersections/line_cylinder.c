/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:22:18 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/23 11:22:18 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int bottom_cap_intersection(t_cylinder cylinder, t_vector ray_direction, t_vector point)
{
	t_vector intersect;
	t_vector axis_direction;
	double dot_product;
	double t;
	double distance;

	axis_direction = _multiply(cylinder.axis_direction, -1);
	dot_product = _dot(axis_direction, ray_direction);
	if (fabs(dot_product) < 0.00001)
		return (FALSE);
	t = _dot(axis_direction, _subtract(cylinder.center, point)) / dot_product;
	if (t < 0)
		return (FALSE);
	intersect = _add(point, _multiply(ray_direction, t));
	distance = _len(_subtract(cylinder.center, intersect));
	if (distance <= cylinder.diameter / 2)
		return (TRUE);
	return (FALSE);
}

int top_cap_intersection(t_cylinder cylinder, t_vector ray_direction, t_vector point)
{
	t_vector intersect;
	t_vector apex;
	double dot_product;
	double t;
	double distance;

	apex = _add(cylinder.center, _multiply(cylinder.axis_direction, cylinder.height));
	dot_product = _dot(cylinder.axis_direction, ray_direction);
	if (fabs(dot_product) < 0.00001)
		return (FALSE);
	t = _dot(cylinder.axis_direction, _subtract(apex, point)) / dot_product;
	if (t < 0)
		return (FALSE);
	intersect = _add(point, _multiply(ray_direction, t));
	distance = _len(_subtract(apex, intersect));
	if (distance <= cylinder.diameter / 2)
		return (TRUE);
	return (FALSE);
}

int line_cylinder(void *object, t_line line, t_vector *result)
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

	t_cylinder cylinder;

	cylinder = *((t_cylinder*)object);
	cylinder.axis_direction = _divide(cylinder.axis_direction, _len(cylinder.axis_direction));
    apex = _add(cylinder.center, _multiply(cylinder.axis_direction, cylinder.height / 2));

	h = _multiply(_subtract(apex, cylinder.center), 2);
	h_normal = _divide(h, _len(h));
	w = _subtract(line.base, cylinder.center);
	v = _divide(line.direction, _len(line.direction));

	a = _dot(v, v) - pow(_dot(v, h_normal), 2);
	b = 2 * (_dot(v, w) - _dot(v, h_normal) * _dot(w, h_normal));
	c = _dot(w, w) - pow(_dot(w, h_normal),2) - pow(cylinder.diameter / 2, 2);

	root_term = pow(b, 2) - (4 * a * c);

	if (root_term > 0)
	{
		t1 = (-b + sqrt(root_term)) / (2 * a);
		t2 = (-b - sqrt(root_term)) / (2 * a);
		if (t1 < t2 && t1 > 0)
			t = t1;
		else if (t2 > 0)
			t = t2;
		point = _add(line.base, _multiply(v, t));
		check =  _dot(_subtract(point, cylinder.center), h);

		if (0 <= check && check <= _len(h))
		{
			*result = point;
			return (TRUE);
		}
		if (_len(h) < check)
		{
			if (top_cap_intersection(cylinder, line.direction, point) == TRUE)
			{
                printf("top cap\n");
				*result = point;
				return (TRUE);
			}
		}
        if (0 > check)
        {
            if (bottom_cap_intersection(cylinder, line.direction, point) == TRUE)
            {
                printf("bottom cap\n");
                *result = point;
                return (TRUE);
            }
        }
	}
	return (FALSE);
}


//https://nachodevblog.com/posts/ray-cylinder-intersection/
