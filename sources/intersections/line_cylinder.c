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

int line_cylinder(t_cylinder cylinder, t_line line, t_vector *result)
{
	t_vector RDf;
	t_vector P;
	t_vector Yd;
	float c;
	float angle_alpha;
	float length_TC;
	float length_TI;
	float length_IP;
	float length_TP;
	float length_PP;
	float cosinus_beta;
	float cosinus_w;
	float D;

	RDf = line.direction;
	RDf.y = 0;
	c = dot(RDf, cylinder.center);
	angle_alpha = acosf(c);
	length_TC = sinf(angle_alpha) * vector_len(cylinder.center);
	if (length_TC > cylinder.diameter / 2)
		return (FALSE);
	length_TI = sqrtf(powf(cylinder.diameter / 2, 2) - powf(vector_len(cylinder.center), 2));
	length_TP = dot(cylinder.center, RDf);
	length_IP = length_TP - length_TI;
	cosinus_beta = dot(line.direction, cylinder.center);
	length_PP = length_IP / cosinus_beta;
	P = vector_add(line.base, vector_multiply(line.direction, length_PP));
	if (P.y > cylinder.height / 2)
		return (FALSE);
	if (line.direction.y <= 0)
		Yd.y = -1;
	else
		Yd.y = 1;
	Yd.x = 0;
	Yd.z = 0;
	cosinus_w = dot(line.direction, Yd);
	D = cylinder.height /cosinus_w;
	P = vector_add(line.base, vector_multiply(line.direction, D));
	if (sqrtf(powf(P.x, 2) + powf(P.z, 2)) > cylinder.diameter / 2)
		return (FALSE);
	*result = P;
	return (TRUE);
}
