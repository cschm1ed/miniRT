/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colour.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:34:01 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/20 13:16:51 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

inline t_vector	get_colour_sphere(t_list *obj)
{
	return (_divide(colour_to_vector(((t_sphere *)obj->content) \
			->colour), 255));
}

inline t_vector	get_colour_plane(t_list *obj)
{
	return (_divide(colour_to_vector(((t_plane *)obj->content) \
			->colour), 255));
}

inline t_vector	get_colour_cylindner(t_list *obj)
{
	return (_divide(colour_to_vector(((t_cylindner *)obj->content) \
			->colour), 255));
}

inline t_vector	get_colour_triangle(t_list *obj)
{
	return (_divide(colour_to_vector(((t_triangle *)obj->content) \
			->colour), 255));
}

inline t_vector	get_colour_lightsource(t_list *obj)
{
	return (_divide(colour_to_vector(((t_light_source *)obj->content) \
			->colour), 255));
}
