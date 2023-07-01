/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_between_vectors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:33:17 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/26 17:33:17 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	angle_between_vectors(t_vector v1, t_vector v2)
{
	return (rad_to_deg(acos(_dot(v1, v2) / (vector_len(v1) * vector_len(v2)))));
}
