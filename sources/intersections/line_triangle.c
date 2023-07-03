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

int check_triangleIntersect(t_triangle triangle, t_vector intersection_point, t_vector n)
{
	int check;

	check = 0;
	if (_dot(_cross(_subtract(triangle.B, triangle.A), _subtract(intersection_point, triangle.A)), n) >= 0)
		check++;
	if (_dot(_cross(_subtract(triangle.C, triangle.B), _subtract(intersection_point, triangle.B)), n) >= 0)
		check++;
	if (_dot(_cross(_subtract(triangle.A, triangle.C), _subtract(intersection_point, triangle.C)), n) >= 0)
		check++;
	if (check == 3)
		return (TRUE);
	return (FALSE);
}
int intersection_line_triangle(t_triangle triangle, t_line line, t_vector *result)
{
	t_vector	n;
	t_vector 	intersection_point;
	double		d;
	double		t;

	n = _cross(_subtract(triangle.B, triangle.A), _subtract(triangle.C, triangle.A));
	n = _divide(n, _len(n));
	d = _dot(n, triangle.A);
	t = (d - _dot(n, line.base));
	if (_dot(n , line.direction) == 0)
		return (FALSE);
	t = t / _dot(n, line.direction);
	if (t < 0)
		return (FALSE);
	intersection_point = _add(line.base, _multiply(line.direction, t));
	if (check_triangleIntersect(triangle, intersection_point, n) == TRUE)
	{
		*result = intersection_point;
		return (TRUE);
	}
	return (FALSE);
}





//Determine the Intersection Point with the Plane:
//Next, we need to find where the vector intersects the plane z = 0. Let's say the vector is defined by a starting point S (2, 4, 2) and a direction D (-1, -1, -1).
//To find the intersection point, we substitute the parametric equation of the vector into the plane equation and solve for t:
//
//x = Sx + t * Dx
//y = Sy + t * Dy
//z = Sz + t * Dz
//
//Substituting the values, we get:
//
//x = 2 + t * (-1) /-1 = gleich direction vector
//y = 4 + t * (-1)
//z = 2 + t * (-1)
//
//Since the plane equation is z = 0, we can solve for t:
//
//2 + t * (-1) = 0
//t = 2
//
//Therefore, the intersection point with the plane is:
//
//x = 2 + 2 * (-1) = 0
//y = 4 + 2 * (-1) = 2
//z = 2 + 2 * (-1) = 0
//
//The intersection point is (0, 2, 0).
//
////t_vector	_subtract(t_vector v1, t_vector v2)
////{
////	t_vector	out;
////
////	out.x = v1.x - v2.x;
////	out.y = v1.y - v2.y;
////	out.z = v1.z - v2.z;
////	return (out);
////}
////
////t_vector	_cross(t_vector v1, t_vector v2)
////{
////	t_vector _cross_product;
////
////	_cross_product.x = (v1.y * v2.z) - (v1.z * v2.y);
////	_cross_product.y = (v1.z * v2.x) - (v1.x * v2.z);
////	_cross_product.z = (v1.x * v2.y) - (v1.y * v2.x);
////	return (_cross_product);
//}

//https://courses.cs.washington.edu/courses/cse457/09sp/lectures/triangle_intersection.pdf
