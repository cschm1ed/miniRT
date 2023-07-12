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

t_vector normal_sphere(void *sphere, t_line line, t_vector point)
{
	t_sphere	*sp;
    t_vector    n;
    (void)line;
	sp = (t_sphere*)((t_list*)sphere)->content;
    n = _subtract(sp->center, point);
	return (_divide(n, _len(n)));
}
