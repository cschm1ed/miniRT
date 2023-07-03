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

int quadratic_equation(float a, float b, float c, float *result);
{
	float result_1;
	float result_2;

	if (sqrf((pow(b, 2) - 4 * a * c)) / 2 * a) < 0)
		return (FALSE);
	result_1 = -b + sqrf((pow(b, 2) - 4 * a * c)) / 2 * a);
	if (result_1 >= 0
	{
		*result = result1;
		return (TRUE);
	}
	result2 = -b - sqrf((pow(b, 2) - 4 * a * c)) / 2 * a);
	*result = result2
	return (TRUE);
}
#include "../../includes/minirt.h"

int line_cone(t_cone cone, t_line line, t_vector *result)
{
	float a;
	float b;
	float c;

	float x;

	float AD_D;
	float AD_OA;
	float D_OA;

	AD_D = dot(cone.axis_direction, line.direction);
	AD_OA = dot(cone.axis_direction, subtract(line.base, cone.apex);
	D_OA = dot(line.direction, subtract(line.base, cone.apex));
	a = pow(AD_D, 2) - pow(cone.opening_angle, 2);
	b = 2 * (AD_D * AD_OA - D_OA * pow(cone.opening_angle, 2));
	c = pow(AD_OA, 2) - pow(D_OA, 2) * pow(cone.opening_angle, 2);

	if (quadratic_equation(a, b, c, *result) == FALSE)
		return (FALSE);
}
