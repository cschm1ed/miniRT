/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:22:18 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/23 11:22:18 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int line_cylinder(t_cylinder cylinder, t_line line, t_vector *result)
{
	t_vector t;
	t_vector y;
	t_vector x;


	t = dot(subtract(cylinder.center, line.base), line.direction);
	y = vector_len(subtract(cylinder.center, line_base));
	if (y > cylinder.diameter / 2)
		return (FALSE);
	x =




}
