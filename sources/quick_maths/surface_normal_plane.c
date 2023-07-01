/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_normal_plane.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:29:56 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/26 17:29:56 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector normal_plane(void *plane, t_vector point)
{
	return (_add(point, _cross(((t_plane*)plane)->v1, ((t_plane*)plane)->v2)));
}
