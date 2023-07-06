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

//int line_cylinder(void *object, t_line line, t_vector *result)
//{
//	t_vector h;
//	t_vector apex;
//	t_vector h_normal;
//	double A;
//	double B;
//	double C;
//
//	double t_1;
//	double t_2;
//	t_cylinder cylinder;
//
//	cylinder = *((t_cylinder*)object);
//	line.direction = _divide(line.direction, _len(line.direction));
//	cylinder.axis_direction = _divide(cylinder.axis_direction, _len(cylinder.axis_direction));
//
//	apex = _add(cylinder.center, _multiply(cylinder.axis_direction, cylinder.height));
//	h = _subtract(apex, cylinder.center);
//	h_normal = _divide(h, _len(h));
//	/*h=(H−C)ĥ =(H−C)‖H−C‖*/
//
////	A = ||V||^2 * ||D||^2
////	B = 2((V dot D)(P - O) dot D - (V dot D)^2)
////	C = ||P - O||^2 * ||D||^2 - ((P - O) dot D)^2 - r^2
////
////	At^2 + Bt + C = 0 what the equation to solve for t
////
////			ChatGPT
////	To solve the quadratic equation At^2 + Bt + C = 0, you can use the quadratic formula:
////
////	t = (-B ± √(B^2 - 4AC)) / (2A)
//
//	A = pow(_len(line.direction), 2);
//	A *= pow(_len(h_normal), 2);
//	B = 2 * (_dot(line.direction, cylinder.axis_direction) * _dot(_subtract(line.base, cylinder.center), h_normal) - pow(_dot(line.direction, h_normal), 2));
//	C = pow(_len(_subtract(line.base, cylinder.center)), 2);
//	C *= pow(_len(h_normal), 2) - pow(_dot(_subtract(line.base, cylinder.center), h_normal), 2);
//	C -= pow(cylinder.diameter / 2, 2);
//
//	t_1 = (-1) * B + sqrt(pow(B, 2) - 4 * A * C);
//	t_1 /= 2 * A;
//	if (t_1 > 0)
//	{
//		*result = _add(line.base, _multiply(line.direction, t_1));
//		return (TRUE);
//	}
//
//	t_2 = (-1) * B - sqrt((pow(B, 2) - 4 * A * C) / 2 * A);
//	if (t_2 > 0)
//	{
//		*result = _add(line.base, _multiply(line.direction, t_2));
//		return (TRUE);
//	}
//	return (FALSE);
//}
int line_cylinder(void *object, t_line line, t_vector *result)
{
	double a;
	double b;
	double c;
	double delta;
	double t1;
	double t2;
	double t;
	double r;
	t_cylinder cylinder;

	cylinder = *((t_cylinder*)object);


	a = (line.direction.x * line.direction.x) + (line.direction.z * line.direction.z);
	b = 2 * (line.direction.x * (line.base.x - cylinder.center.x) + line.direction.z * (line.base.z - cylinder.center.z));
	c = (line.base.x - cylinder.center.x) * (line.base.x -cylinder.center.x) + (line.base.z - cylinder.center.z) * (line.base.z - cylinder.center.z) - (cylinder.diameter / 2 * cylinder.diameter / 2);
	delta = b * b - 4 * (a * c);
	if (fabs(delta) < 0.001)
		return (FALSE);
	if (delta < 0)
		return (FALSE);
	t1 = (-b - sqrt(delta)) / (2 * a);
	t2 = (-b + sqrt(delta)) / (2 * a);
	if (t1 > t2)
		t = t2;
	else
		t = t1;
	r = line.base.y + t * line.direction.y;
	if ((r >= cylinder.center.y) && (r <= cylinder.center.y + cylinder.height))
		return (FALSE);
	*result = _add(line.base, _multiply(line.direction, t));
	return (TRUE);
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
