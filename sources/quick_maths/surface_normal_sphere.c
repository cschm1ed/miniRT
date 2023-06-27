/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_normal_sphere.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:27:50 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/26 17:27:50 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector normal_sphere(void *sphere, t_vector point)
{
	return (vector_add(subtract(point, ((t_sphere*)sphere)->center), ((t_sphere*)sphere)->center));
}
