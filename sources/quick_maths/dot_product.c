/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 08:38:53 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/22 08:38:53 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	dot(t_vector v1, t_vector v2)
{
	float dot_product;

	dot_product = 0;
	dot_product += v1.x * v2.x;
	dot_product += v1.y * v2.y;
	dot_product += v1.z * v2.z;
	return (dot_product);
}
