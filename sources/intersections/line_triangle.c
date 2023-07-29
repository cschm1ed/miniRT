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
	if (_dot(_cross(_subtract(triangle.b, triangle.a),
				_subtract(intersection_point, triangle.a)), n) >= 0)
		check ++;
	if (_dot(_cross(_subtract(triangle.a, triangle.c),
				_subtract(intersection_point, triangle.c)), n) >= 0)
		check ++;
	if (_dot(_cross(_subtract(triangle.c, triangle.b),
				_subtract(intersection_point, triangle.b)), n) >= 0)
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
	n = _cross(_subtract(triangle.b, triangle.a),
			_subtract(triangle.c, triangle.a));
	n = _divide(n, _len(n));
	d = _dot(n, triangle.a);
	t = (d - _dot(n, line.base));
	if (_dot(n, line.dir) == 0)
		return (FALSE);
	t = t / _dot(n, line.dir);
	if (t < 0)
		return (FALSE);
	intersection_point = _add(line.base, _multiply(line.dir, t));
	if (check_triangleintersect(triangle, intersection_point, n) == TRUE)
	{
		inter->point = intersection_point;
		inter->normal = n;
		return (TRUE);
	}
	return (FALSE);
}
