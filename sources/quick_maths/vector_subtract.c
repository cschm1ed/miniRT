/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecotr__subtract.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 08:57:59 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/22 08:57:59 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector	_subtract(t_vector v1, t_vector v2)
{
	t_vector	out;

	out.x = v1.x - v2.x;
	out.y = v1.y - v2.y;
	out.z = v1.z - v2.z;
	return (out);
}
