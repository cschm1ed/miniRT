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

//int quadratic_equation(float a, float b, float c, t_intersect *inter)
//{
//	double result_1;
//	double result_2;
//
//	t_vector i;
//	t_vector j;
//
//	if (sqrt((pow(b, 2) - 4 * a * c) / 2 * a) < 0)
//		return (FALSE);
//	result_1 = -b + sqrt((pow(b, 2) - 4 * a * c) / 2 * a);
//	if (result_1 >= 0)
//	{
//		inter->point = i;
//		return (TRUE);
//	}
//	result_2 = -b - sqrt((pow(b, 2) - 4 * a * c) / 2 * a);
//	inter->point = j;
//	return (TRUE);
//}
//
//int line_cone(void *object, t_line line, t_intersect *inter)
//{
//	float a;
//	float b;
//	float c;
//
//	float x;
//
//	float AD_D;
//	float AD_OA;
//	float D_OA;
//
//	t_cone cone;
//
//	cone = *((t_cone*)object);
//
//	AD_D = _dot(cone.axis_direction, line.direction);
//	AD_OA = _dot(cone.axis_direction, _subtract(line.base, cone.apex);
//	D_OA = _dot(line.direction, _subtract(line.base, cone.apex));
//	a = pow(AD_D, 2) - pow(cone.opening_angle, 2);
//	b = 2 * (AD_D * AD_OA - D_OA * pow(cone.opening_angle, 2));
//	c = pow(AD_OA, 2) - pow(D_OA, 2) * pow(cone.opening_angle, 2);
//
//	if (quadratic_equation(a, b, c, inter) == FALSE)
//		return (FALSE);
//	return (SUCCESS);
//}
