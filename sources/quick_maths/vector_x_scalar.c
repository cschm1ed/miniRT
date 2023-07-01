/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_x_scalar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:03:18 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/23 18:03:18 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector vector_x_scalar(t_vector vector, double scalar)
{
	t_vector result;

	result.x = vector.x * scalar;
	result.y = vector.y * scalar;
	result.z = vector.z * scalar;
	return (result);
}

double vector_scalar(t_vector vector1, t_vector vector2)
{
	double result;

	result = (vector1.x * vector2.x) + (vector1.y * vector2.y) + (vector1.z * vector2.z);
	return (result);
}
