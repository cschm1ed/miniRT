/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_scene_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:20:21 by estruckm          #+#    #+#             */
/*   Updated: 2023/07/20 13:31:01 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	interpret_lightsource(char **str, t_data *data)
{
	t_list			*new_element;
	t_light_source	*new_light;

	new_light = malloc(sizeof(t_light_source));
	if (check_light_source(new_light, str) == FAILURE)
		return (FAILURE);
	new_element = ft_lstnew(new_light);
	new_element->get_colour = get_colour_lightsource;
	ft_lstadd_back(&data->scene->light_lst, new_element);
	return (SUCCESS);
}

int	interpret_camera(char **str, t_data *data)
{
	t_camera	*new_camera;

	new_camera = malloc(sizeof(t_camera));
	if (check_camera(new_camera, str) == FAILURE)
	{
		return (FAILURE);
	}
	data->scene->camera = new_camera;
	return (SUCCESS);
}

int	interpret_ambient_light(char **str, t_data *data)
{
	t_ambient_light	*new_ambient_light;

	new_ambient_light = malloc(sizeof(t_ambient_light));
	if (check_ambient_light(new_ambient_light, str) == FAILURE)
		return (FAILURE);
	data->scene->ambient_light = new_ambient_light;
	return (SUCCESS);
}

int	interpret_plane(char **str, t_data *data)
{
	t_list	*new_element;
	t_plane	*new_plane;

	new_plane = malloc(sizeof(t_plane));
	new_element = ft_lstnew(new_plane);
	new_element->diffuse = DIFFUSE;
	new_element->specular = SPECULAR;
	new_element->reflective = REFLECTIVENES;
	if (check_plane(new_plane, new_element, str) == FAILURE)
		return (FAILURE);
	new_plane->v2 = (t_vector){0, 0, 0};
	new_element->flag = 1;
	new_element->intersection = intersection_line_plane;
	new_element->get_colour = get_colour_plane;
	ft_lstadd_back(&data->scene->all_objs, new_element);
	return (SUCCESS);
}

int	interpret_sphere(char **str, t_data *data)
{
	t_list		*new_element;
	t_sphere	*new_sphere;

	new_sphere = malloc(sizeof(t_sphere));
	new_element = ft_lstnew(new_sphere);
	new_element->diffuse = DIFFUSE;
	new_element->specular = SPECULAR;
	new_element->reflective = REFLECTIVENES;
	if (check_sphere(new_sphere, new_element, str) == FAILURE)
		return (FAILURE);
	new_element->flag = 2;
	new_element->intersection = intersection_line_sphere;
	new_element->get_colour = get_colour_sphere;
	ft_lstadd_back(&data->scene->all_objs, new_element);
	return (SUCCESS);
}
