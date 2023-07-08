/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 02:31:48 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/27 02:32:03 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector	_multiply(t_vector vector, double factor)
{
	t_vector out;

	out.x = vector.x * factor;
	out.y = vector.y * factor;
	out.z = vector.z * factor;
	return (out);
}

t_vector	_divide(t_vector vector, double factor)
{
	t_vector out;

	if (factor == 0)
		return (vector);
	out.x = vector.x / factor;
	out.y = vector.y / factor;
	out.z = vector.z / factor;
	return (out);
}

t_vector _multiply_element_wise(t_vector v1, t_vector v2)
{
	t_vector out;

	out.x = v1.x * v2.x;
	out.y = v1.y * v2.y;
	out.z = v1.z * v2.z;
	return (out);
}
