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


//int cap_intersection_test(t_cylinder cylinder, t_line line, t_vector height, double )
//{
//
//}
int line_cylinder(void *object, t_line line, t_vector *result)
{
	t_vector h;
	t_vector apex;
	t_vector h_normal;
	t_vector w;
	t_vector line_normal;
	t_vector check;
	double a;
	double b;
	double c;

	double t1;
	double t2;
	double t;
	double root_term;
	t_cylinder cylinder;


	cylinder = *((t_cylinder*)object);
	line_normal = _divide(line.direction, _len(line.direction));
	cylinder.axis_direction = _divide(cylinder.axis_direction, _len(cylinder.axis_direction));

	apex = _add(cylinder.center, _multiply(cylinder.axis_direction, cylinder.height));
	h = _subtract(apex, cylinder.center);
	h_normal = _divide(h, _len(h));
	w = _subtract(line.base, cylinder.center);
	/*h=(H−C)ĥ =(H−C)‖H−C‖*/

//	A = ||V||^2 * ||D||^2
//	B = 2((V dot D)(P - O) dot D - (V dot D)^2)
//	C = ||P - O||^2 * ||D||^2 - ((P - O) dot D)^2 - r^2
//
//	At^2 + Bt + C = 0 what the equation to solve for t
//
//			ChatGPT
//	To solve the quadratic equation At^2 + Bt + C = 0, you can use the quadratic formula:
//
//	t = (-B ± √(B^2 - 4AC)) / (2A)

	a = _dot(line.direction, line.direction) - pow(_dot(line.direction, h_normal), 2);
	b = 2 * (_dot(line.direction, w) - _dot(line.direction, h_normal) * _dot(w, h_normal));
	c = _dot(w, w) - pow(_dot(w, h_normal),2) - pow(cylinder.diameter / 2, 2);
	root_term = pow(b, 2) - (4 * a * c);
	if (root_term > 0)
	{
		t1 = (-1) * b + sqrt(pow(b, 2) - 4 * a * c);
		t2 = (-1) * b - sqrt(pow(b, 2) - 4 * a * c);
		if (t1 > t2)
			t = t1;
		else
			t = t2;
		check = _add(line.base, _multiply(line.direction, t));
		if (0 <= _dot(_subtract(check, cylinder.center), h) &&  _dot(_subtract(check, cylinder.center), h) <= _len(h))
		{
			*result = _add(line.base, _multiply(line.direction, t));
			return (TRUE);
		}
	}
	if (root_term == 0)
		return (FALSE);
	if (fabs(_dot(line_normal, h_normal)) != 1)
	{
		t = (-1) * b / 2 * a;
		*result = _add(line.base, _multiply(line.direction, t));
		return (TRUE);
	}
	if (root_term < 0)
		return (FALSE);
	return (FALSE);
}


//float Cylinder::intersect(Vector pos, Vector dir)
//{
//	float a = (dir.x * dir.x) + (dir.z * dir.z);
//	float b = 2*(dir.x*(pos.x-center.x) + dir.z*(pos.z-center.z));
//	float c = (pos.x - center.x) * (pos.x - center.x) + (pos.z - center.z) * (pos.z - center.z) - (radius*radius);
//
//	float delta = b*b - 4*(a*c);
//	if(fabs(delta) < 0.001) return -1.0;
//	if(delta < 0.0) return -1.0;
//
//	float t1 = (-b - sqrt(delta))/(2*a);
//	float t2 = (-b + sqrt(delta))/(2*a);
//	float t;
//
//	if (t1>t2) t = t2;
//	else t = t1;
//
//	float r = pos.y + t*dir.y;
//
//	if ((r >= center.y) and (r <= center.y + height))return t;
//	else return -1;
//}
//int line_cylinder(t_cylinder cylinder, t_line line, t_vector *result)
//{
//	t_vector RDf;
//	t_vector P;
//	t_vector Yd;
//	double c;
//	double angle_alpha;
//	double length_TC;
//	double length_TI;
//	double length_IP;
//	double length_TP;
//	double length_PP;
//	double cosinus_beta;
//	double cosinus_w;
//	double D;
//
//	RDf = line.direction;
//	RDf.y = 0;
//	c = _dot(RDf, cylinder.center);
//	angle_alpha = acos(c);
//	length_TC = sin(angle_alpha) * _len(cylinder.center);
//	if (length_TC > cylinder.diameter / 2)
//		return (FALSE);
//	length_TI = sqrt(pow(cylinder.diameter / 2, 2) - pow(_len(cylinder.center), 2));
//	length_TP = _dot(cylinder.center, RDf);
//	length_IP = length_TP - length_TI;
//	cosinus_beta = _dot(line.direction, cylinder.center);
//	length_PP = length_IP / cosinus_beta;
//	P = _add(line.base, _multiply(line.direction, length_PP));
//	if (P.y > cylinder.height / 2)
//		return (FALSE);
//	if (line.direction.y <= 0)
//		Yd.y = -1;
//	else
//		Yd.y = 1;
//	Yd.x = 0;
//	Yd.z = 0;
//	cosinus_w = _dot(line.direction, Yd);
//	D = cylinder.height /cosinus_w;
//	P = _add(line.base, _multiply(line.direction, D));
//	if (sqrt(pow(P.x, 2) + pow(P.z, 2)) > cylinder.diameter / 2)
//		return (FALSE);
//	*result = P;
//	return (TRUE);
//}


//https://nachodevblog.com/posts/ray-cylinder-intersection/
