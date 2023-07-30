/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colour2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 23:19:45 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/28 23:19:46 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

inline t_vector	get_colour_triangle(t_list *obj)
{
	return (_divide(colour_to_vector(((t_triangle *)obj->content)->colour), 255));
}

inline t_vector get_colour_cone(t_list *obj)
{
	return (_divide(colour_to_vector(((t_cone *)obj->content)->colour), 255));
}

inline t_vector	get_colour_lightsource(t_list *obj)
{
	return (_divide(colour_to_vector((\
		(t_light_source *)obj->content)->colour), 255));
}
