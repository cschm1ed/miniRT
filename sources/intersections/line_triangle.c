/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:53:43 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/26 18:54:05 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	check_triangleintersect(t_triangle triangle,
		t_vector intersection_point, t_vector n)
{
	int	check;

	check = 0;
	if (_dot(_cross(_subtract(triangle.B, triangle.A),
				_subtract(intersection_point, triangle.A)), n) >= 0)
		check ++;
	if (_dot(_cross(_subtract(triangle.A, triangle.C),
				_subtract(intersection_point, triangle.C)), n) >= 0)
		check ++;
	if (_dot(_cross(_subtract(triangle.C, triangle.B),
				_subtract(intersection_point, triangle.B)), n) >= 0)
		check ++;
	if (check == 3)
		return (TRUE);
	return (FALSE);
}

int	intersection_line_triangle(void *object, t_line line, t_intersect *inter)
{
	t_vector	n;
	t_vector	intersection_point;
	t_triangle	triangle;
	double		d;
	double		t;

	triangle = *((t_triangle *)object);
	n = _cross(_subtract(triangle.B, triangle.A),
			_subtract(triangle.C, triangle.A));
	n = _divide(n, _len(n));
	d = _dot(n, triangle.A);
	t = (d - _dot(n, line.base));
	if (_dot(n, line.direction) == 0)
		return (FALSE);
	t = t / _dot(n, line.direction);
	if (t < 0)
		return (FALSE);
	intersection_point = _add(line.base, _multiply(line.direction, t));
	if (check_triangleintersect(triangle, intersection_point, n) == TRUE)
	{
		inter->point = intersection_point;
		inter->normal = n;
		return (TRUE);
	}
	return (FALSE);
}
