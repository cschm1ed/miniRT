/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 08:51:45 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/22 08:51:45 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	vector_len(t_vector vec)
{
	float out;

	out = pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2);
	out = sqrtf(out);
	return (out);
}
