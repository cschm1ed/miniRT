/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_cone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:53:13 by estruckm          #+#    #+#             */
/*   Updated: 2023/07/01 15:53:13 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int quadratic_equation(double a, double b, double c)
{
	double result_1;
	double result_2;
	double t;
//	if (pow(b, 2) - (4 * a * c) > 0)
//	{
		result_1 = -b + sqrt((pow(b, 2) - 4 * a * c) / 2 * a);
		result_2 = -b - sqrt((pow(b, 2) - 4 * a * c) / 2 * a);
		if (result_1 > result_2)
			t = result_2;
		else
			t = result_1;
	return (t);
}

void calculate_intersection(double t, t_line line, t_intersect *inter)
{
	inter->point = _add(line.base, _multiply(line.direction, t);
}

int cap_intersection(t_cone cone, t_vector ray_direction, t_vector point)
{
	t_vector intersect;
	t_vector center;
	double radius;
	double t;
	double distance;

	center = _add(cone.apex, _multiply(cone.axis_direction, cone.height));
	radius = tan(cone.opening_angle / 2) / _len()
	if (fabs( _dot(cone.axis_direction, ray_direction)) < 0.00001)
		return (FALSE);
	t = _dot(cone.axis_direction, _subtract(center, point)) / dot_product;
	if (t < 0)
		return (FALSE);
	intersect = _add(point, _multiply(ray_direction, t));
	distance = _len(_subtract(center, intersect));
	if (distance <=  / 2)
		return (TRUE);
	return (FALSE);
}


int line_cone(void *object, t_line line, t_intersect *inter)
{
	double a;
	double b;
	double c;
	double len_q;
	double t;

	t_cone cone;
	t_vector d;
	t_vector p;
	t_vector q;

	cone = *((t_cone*)object);

	d = line.direction;
	p = line.base;

//	B = 2 * (P0x * Dx + P0y * Dy - P0z * Dz * tan^2(θ))
//	C = P0x^2 + P0y^2 - P0z^2 * tan^2(θ)

	a = pow(d.x, 2) + pow(d.y, 2) - pow(d.z, 2) * pow(tan(cone.opening_angle / 2), 2);
	b = 2 * (p.x * d.x + p.y * p.y - p.z * d.z * pow(tan(cone.opening_angle / 2), 2));
	c = pow(p.x, 2) + pow(p.y, 2) - pow(p.z, 2) * pow(tan(cone.opening_angle / 2), 2);

	if (pow(b, 2) - (4 * a * c) > 0)
	{
		t = quadratic_equation(a, b, c);

		inter->point = _add(line.base, _multiply(line.direction, t));
		if ()
		len_q = _len(_subtract(cone.apex, inter->point)) / cos(cone.opening_angle / 2);
		q = _add(cone.apex, _multiply(cone.axis_direction, len_q));
		inter->normal = _subtract(inter->point, q);
		return (TRUE);
	}

	if (quadratic_equation(a, b, c, inter) == FALSE)
		return (FALSE);
	return (SUCCESS);
}



