/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pow_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:31:23 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/30 14:58:27 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector	_pow(t_vector vector)
{
	t_vector	out;

	out.x = pow(vector.x, 2);
	out.y = pow(vector.y, 2);
	out.z = pow(vector.z, 2);
	return (out);
}
