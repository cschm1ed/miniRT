/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 02:31:48 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/27 02:32:03 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	vector_multiply(t_vector vector, float factor)
{
	vector.x = vector.x * factor;
	vector.y = vector.y * factor;
	vector.z = vector.z * factor;
}

void	vector_divide(t_vector vector, float factor)
{
	vector.x = vector.x / factor;
	vector.y = vector.y / factor;
	vector.z = vector.z / factor;
}
