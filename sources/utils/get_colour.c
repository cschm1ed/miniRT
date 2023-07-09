/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colour.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:34:01 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/08 12:58:50 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector get_colour_sphere(t_list *obj)
{
	return (_divide(colour_to_vector(((t_sphere*)obj->content)->colour), 255));
}

t_vector get_colour_plane(t_list *obj)
{
	return (_divide(colour_to_vector(((t_plane*)obj->content)->colour), 255));
}

t_vector get_colour_cylinder(t_list *obj)
{
	return (_divide(colour_to_vector(((t_cylinder*)obj->content)->colour), 255));
}

t_vector get_colour_triangle(t_list *obj)
{
	return (_divide(colour_to_vector(((t_triangle*)obj->content)->colour), 255));
}

t_vector get_colour_lightsource(t_list *obj)
{
	return (_divide(colour_to_vector(((t_light_source*)obj->content)->colour), 255));
}
