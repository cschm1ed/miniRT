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
	double c;
	double angle_alpha;
	double length_TC;
	double length_TI;
	double length_IP;
	double length_TP;
	double length_PP;
	double cosinus_beta;
	double cosinus_w;
	double D;

	RDf = line.direction;
	RDf.y = 0;
	c = _dot(RDf, cylinder.center);
	angle_alpha = acosf(c);
	length_TC = sinf(angle_alpha) * vector_len(cylinder.center);
	if (length_TC > cylinder.diameter / 2)
		return (FALSE);
	length_TI = sqrtf(powf(cylinder.diameter / 2, 2) - powf(vector_len(cylinder.center), 2));
	length_TP = _dot(cylinder.center, RDf);
	length_IP = length_TP - length_TI;
	cosinus_beta = _dot(line.direction, cylinder.center);
	length_PP = length_IP / cosinus_beta;
	P = _add(line.base, _multiply(line.direction, length_PP));
	if (P.y > cylinder.height / 2)
		return (FALSE);
	if (line.direction.y <= 0)
		Yd.y = -1;
	else
		Yd.y = 1;
	Yd.x = 0;
	Yd.z = 0;
	cosinus_w = _dot(line.direction, Yd);
	D = cylinder.height /cosinus_w;
	P = _add(line.base, _multiply(line.direction, D));
	if (sqrtf(powf(P.x, 2) + powf(P.z, 2)) > cylinder.diameter / 2)
		return (FALSE);
	*result = P;
	return (TRUE);
}
