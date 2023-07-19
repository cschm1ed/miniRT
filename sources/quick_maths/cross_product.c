/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_product.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 08:44:12 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/22 08:44:12 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

inline t_vector	_cross(t_vector v1, t_vector v2)
{
	t_vector	_cross_product;

	_cross_product.x = (v1.y * v2.z) - (v1.z * v2.y);
	_cross_product.y = (v1.z * v2.x) - (v1.x * v2.z);
	_cross_product.z = (v1.x * v2.y) - (v1.y * v2.x);
	return (_cross_product);
}
