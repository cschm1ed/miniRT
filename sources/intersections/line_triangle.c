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

int intersection_line_triangle(t_triangle triangle, t_line line, t_vector *result)
{
	t_vector normalized_Vector;
	float factor_t;
	float factor_d;

//	Normal Vector N = AB × AC = (4, 1, 0) × (2, 5, 0) = (0, 0, 19)
	(void)result;
	normalized_Vector = cross(substract(triangle.C, triangle.A), substract(triangle.B, triangle.A));
	vector_divide(normalized_Vector, vector_len(normalized_Vector));
	factor_d = vector_scalar(normalized_Vector, triangle.A);
	if (vector_scalar(normalized_Vector, line.direction) == 0)
		return (FALSE);
	factor_t = (factor_d - vector_scalar(normalized_Vector, line.base)) / vector_scalar(normalized_Vector, line.direction);
	return (TRUE);
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
////t_vector	vector_substract(t_vector v1, t_vector v2)
////{
////	t_vector	out;
////
////	out.x = v1.x - v2.x;
////	out.y = v1.y - v2.y;
////	out.z = v1.z - v2.z;
////	return (out);
////}
////
////t_vector	cross(t_vector v1, t_vector v2)
////{
////	t_vector cross_product;
////
////	cross_product.x = (v1.y * v2.z) - (v1.z * v2.y);
////	cross_product.y = (v1.z * v2.x) - (v1.x * v2.z);
////	cross_product.z = (v1.x * v2.y) - (v1.y * v2.x);
////	return (cross_product);
//}

//https://courses.cs.washington.edu/courses/cse457/09sp/lectures/triangle_intersection.pdf