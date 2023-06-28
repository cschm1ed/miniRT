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
	if (dot(cross(subtract(triangle.B, triangle.A), subtract(intersection_point, triangle.A)), n) >= 0)
		check++;
	if (dot(cross(subtract(triangle.C, triangle.B), subtract(intersection_point, triangle.B)), n) >= 0)
		check++;
	if (dot(cross(subtract(triangle.A, triangle.C), subtract(intersection_point, triangle.C)), n) >= 0)
		check++;
	if (check == 3)
		return (TRUE);
	return (FALSE);
}
int intersection_line_triangle(t_triangle triangle, t_line line, t_vector *result)
{
	t_vector	n;
	t_vector 	intersection_point;
	float		d;
	float		t;

	n = cross(subtract(triangle.B, triangle.A), subtract(triangle.C, triangle.A));
	n = vector_divide(n, vector_len(n));
	d = dot(n, triangle.A);
	t = (d - dot(n, line.base));
	if (dot(n , line.direction) == 0)
		return (FALSE);
	t = t / dot(n, line.direction);
	intersection_point = vector_add(line.base, vector_multiply(line.direction, t));
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
////t_vector	subtract(t_vector v1, t_vector v2)
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
