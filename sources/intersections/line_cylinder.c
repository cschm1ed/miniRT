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
//	check_
//}

int cap_intersection(t_vector center, t_vector point, double radius, t_vector h)
{
	double check;
	double x;
	double y;
	double z;

	x = pow(point.x - center.x , 2);
	y = pow(point.y - center.y , 2);
	z = pow(point.z - center.z , 2);

	check = x + y + z - pow(radius, 2);
    if (_len(_subtract(point, center)) < 2)
        return (TRUE);

	if (check <= 0.0001)
		return (TRUE);
	return (FALSE);
}

int cap_intersection2(t_vector center, t_vector point, double radius, t_vector h)
{

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

		if (_len(h) < check)
		{
			if (cap_intersection(apex, point, cylinder.diameter / 2, h) == TRUE)
			{
                printf("top cap\n");
				*result = point;
				return (TRUE);
			}
		}
		if (0 <= check && check <= _len(h))
		{
			*result = point;
			return (TRUE);
		}
        if (0 > check)
        {
            if (cap_intersection(cylinder.center, point, cylinder.diameter / 2, h) == TRUE)
            {
                printf("bottom cap\n");
                *result = point;
                return (TRUE);
            }
        }
	}
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
