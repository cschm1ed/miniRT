/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles_to_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 09:03:27 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/22 09:03:27 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector angles_to_vector(float ayx, float axz)
{
	t_vector out;

	out.x = sin(ayx * M_PI / 180);
	out.y = cos(ayx * M_PI / 180);
	out.z = sin(axz * M_PI / 180);
	return (out);
}
