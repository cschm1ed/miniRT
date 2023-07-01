/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:20:21 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/24 16:30:48 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int interpret_lightsource(char **str, t_data *data)
{
	t_list *new_element;
	t_light_source *new_light;

	new_light = malloc(sizeof(t_light_source));
	if (count_elements(str) != 4)
		ft_printf("Wrong number of elements in light_source, there are %d elements in side\n", 1, count_elements(str));
	else
	{
		if (get_center(str[1], &new_light->center) == FAILURE
			|| get_single_double(str[2], &new_light->light_ratio) == FAILURE
			|| get_trgb(str[3], &new_light->colour) == FAILURE)
		{
			free(new_light);
			return (FAILURE);
		}
	}
	new_element = ft_lstnew(new_light);
	ft_lstadd_back(&data->scene->light_lst, new_element);
//	printf("center.x = %f\n", new_light->center.x);
//	printf("center.y = %f\n", new_light->center.y);
//	printf("center.z = %f\n", new_light->center.z);
//	printf("light ratio = %f\n", new_light->light_ratio);
//	printf("colour = %d\n", new_light->colour);
	return (SUCCESS);
}

int interpret_camera(char **str, t_data *data)
{
	t_camera *new_camera;

	new_camera = malloc(sizeof(t_camera));
	if (count_elements(str) != 4)
	{
		ft_printf("Wrong number of elements in light_source, there are %d elements in side\n", 1, count_elements(str));
		return (FAILURE);
	}
	else
	{
		if (get_center(str[1], &new_camera->center) == FAILURE
			|| get_center(str[2], &new_camera->vector) == FAILURE
			|| get_single_integer(str[3], &new_camera->degrees) == FAILURE)
		{
			free(new_camera);
			return (FAILURE);
		}

	}
	data->scene->camera = new_camera;
	printf("center.x = %f\n", new_camera->center.x);
	printf("center.y = %f\n", new_camera->center.y);
	printf("center.z = %f\n", new_camera->center.z);
	printf("degress = %d\n", new_camera->degrees);
	return (SUCCESS);
}

int interpret_ambient_light(char **str, t_data *data)
{
	t_ambient_light *new_ambient_light;

	new_ambient_light = malloc(sizeof(t_ambient_light));
	if (count_elements(str) != 3)
	{
		ft_printf("Wrong number of elements in light_source, there are %d elements in side\n", 1, count_elements(str));
		return (FAILURE);
	}
	else
	{
		if (get_single_double(str[1], &new_ambient_light->light_ratio) == FAILURE
			|| get_trgb(str[2], &new_ambient_light->colour) == FAILURE)
			return (free(new_ambient_light), FAILURE);
	}
	data->scene->ambient_light = new_ambient_light;
//	printf("light_ratio = %f\n", new_ambient_light->light_ratio);
//	printf("colour = %d\n", new_ambient_light->colour);
	return (SUCCESS);
}

int interpret_plane(char **str, t_data *data)
{
	t_list *new_element;
	t_plane *new_plane;

	new_plane = malloc(sizeof(t_plane));
	if (count_elements(str) != 5)
		return (ft_printf("Wrong number of elements in light_source, there are %d elements in side\n",
			1, count_elements(str)), FAILURE);
	else
	{
		if (get_center(str[1], &new_plane->base) == FAILURE
			|| get_center(str[2], &new_plane->v1) == FAILURE
            || get_center(str[3], &new_plane->v2) == FAILURE
			|| get_trgb(str[4], &new_plane->colour) == FAILURE)
			return (free(new_plane), FAILURE);
	}
	new_element = ft_lstnew(new_plane);
	new_element->flag = 1;
	new_element->intersection = intersection_line_plane;
	new_element->surface_normal = normal_plane;
	ft_lstadd_back(&data->scene->plane_lst, new_element);
//	printf("light_ratio = %f\n", new_ambient_light->light_ratio);
	//printf("new plane colour = %d\n", new_plane->colour);
	return (SUCCESS);
}

int interpret_sphere(char **str, t_data *data)
{
	t_list *new_element;
	t_sphere *new_sphere;

	new_sphere = malloc(sizeof(t_sphere));
	if (count_elements(str) != 4)
		return (ft_printf("Wrong number of elements in light_source, there are %d elements in side\n",
			1, count_elements(str)),FAILURE);
	else
	{
		if (get_center(str[1], &new_sphere->center) == FAILURE
			|| get_single_double(str[2], &new_sphere->diameter) == FAILURE
			|| get_trgb(str[3], &new_sphere->colour) == FAILURE)
			return (free(new_sphere), FAILURE);
	}
	new_element = ft_lstnew(new_sphere);
	new_element->flag = 2;
	new_element->intersection = intersection_line_sphere;
	new_element->surface_normal = normal_sphere;
	ft_lstadd_back(&data->scene->sphere_lst, new_element);
	printf("parsing Sphere: center %f,%f,%f colour = %d\n", new_sphere->center.x, new_sphere->center.y, new_sphere->center.z, new_sphere->colour);
	return (SUCCESS);
}

int interpret_cylinder(char **str, t_data *data)
{
	t_list *new_element;
	t_cylinder *new_cylinder;

	new_cylinder = malloc(sizeof(t_sphere));
	if (count_elements(str) != 6)
	{
		ft_printf("Wrong number of elements in cylinder, there are %d elements in side\n", 1, count_elements(str));
		return (FAILURE);
	}
	else
	{
		if (get_center(str[1], &new_cylinder->center) == FAILURE
			|| get_center(str[2], &new_cylinder->vector) == FAILURE
			|| get_single_double(str[3], &new_cylinder->diameter) == FAILURE
			|| get_single_double(str[4], &new_cylinder->height) == FAILURE
			|| get_trgb(str[5], &new_cylinder->colour) == FAILURE)
		{
			free(new_cylinder);
			return (FAILURE);
		}
	}
	new_element = ft_lstnew(new_cylinder);
	ft_lstadd_back(&data->scene->cylinder_lst, new_element);
	printf("colour_cylinder = %d\n", new_cylinder->colour);
	return (SUCCESS);
}

//cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255

//sp 0,0,20 20 255,0,0

//pl 0,0,0 0,1.0,0 255,0,225

//A 0.2 255,255,255

//C -50,0,20 0,0,0 70

// -40.0,50.0,0.0 	0.6 	10,0,255
