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

static int set_DSR(t_list *obj, char **str, int i);

int interpret_lightsource(char **str, t_data *data)
{
	t_list *new_element;
	t_light_source *new_light;

	new_light = malloc(sizeof(t_light_source));
	if (count_elements(str) != 4)
		ft_printf("Wrong number of elements in light_source, there are %d elements in side\n", 1, count_elements(str));

	printf("check light source \n");
	if (get_center(str[1], &new_light->center) == FAILURE
		|| get_single_double(str[2], &new_light->light_ratio) == FAILURE
		|| get_trgb(str[3], &new_light->colour) == FAILURE)
	{
		printf("check 2\n");
		printf("failure invalid input\n");
		free(new_light);
		return (FAILURE);
	}

	printf("check light source 2\n");
	new_element = ft_lstnew(new_light);
	new_element->get_colour = get_colour_lightsource;
	ft_lstadd_back(&data->scene->light_lst, new_element);
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
			printf("failure invalid input\n");
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
		{
			printf("failure invalid input\n");
			free(new_ambient_light);
			return (FAILURE);
		}
	}
	data->scene->ambient_light = new_ambient_light;
	return (SUCCESS);
}

int interpret_plane(char **str, t_data *data)
{
	t_list *new_element;
	t_plane *new_plane;

	new_plane = malloc(sizeof(t_plane));
    new_element = ft_lstnew(new_plane);
    new_element->diffuse = DIFFUSE;
    new_element->specular = SPECULAR;
    new_element->reflective = REFLECTIVENES;
    if (count_elements(str) != 4)
    {
        if (count_elements(str) == 7)
        {
            if (set_DSR(new_element, str, 4) == FAILURE)
                return (FAILURE);
        }
        else
            return (ft_printf("Wrong number of elements in cylindner, there are %d elements in side\n", 1, count_elements(str)), FAILURE);
    }
    if (get_center(str[1], &new_plane->base) == FAILURE
        || get_center(str[2], &new_plane->v1) == FAILURE
        || get_trgb(str[3], &new_plane->colour) == FAILURE)
	{
		printf("failure invalid input\n");
		free(new_plane);
		return (FAILURE);
	}
	new_element->flag = 1;
	new_element->intersection = intersection_line_plane;
	new_element->surface_normal = normal_plane;
	new_element->get_colour = get_colour_plane;
	ft_lstadd_back(&data->scene->plane_lst, new_element);
	return (SUCCESS);
}

int interpret_sphere(char **str, t_data *data)
{
	t_list *new_element;
	t_sphere *new_sphere;

	new_sphere = malloc(sizeof(t_sphere));
    new_element = ft_lstnew(new_sphere);
    new_element->diffuse = DIFFUSE;
    new_element->specular = SPECULAR;
    new_element->reflective = REFLECTIVENES;
    if (count_elements(str) != 4)
    {
        if (count_elements(str) == 7)
        {
            if (set_DSR(new_element, str, 4) == FAILURE)
                return (FAILURE);
        }
        else
            return (ft_printf("Wrong number of elements in cylindner, there are %d elements in side\n", 1, count_elements(str)), FAILURE);
    }
    if (get_center(str[1], &new_sphere->center) == FAILURE
        || get_single_double(str[2], &new_sphere->diameter) == FAILURE
        || get_trgb(str[3], &new_sphere->colour) == FAILURE)
	{
		printf("failure invalid input\n");
		free(new_sphere);
		return (FAILURE);
	}
	new_element->flag = 2;
	new_element->intersection = intersection_line_sphere;
	new_element->surface_normal = normal_sphere;
	new_element->get_colour = get_colour_sphere;
	ft_lstadd_back(&data->scene->sphere_lst, new_element);
	printf("parsing Sphere: center %f,%f,%f colour = %d\n", new_sphere->center.x, new_sphere->center.y, new_sphere->center.z, new_sphere->colour);
	return (SUCCESS);
}

int interpret_cylindner(char **str, t_data *data)
{
	t_list *new_element;
	t_cylindner *new_cylindner;

	new_cylindner = malloc(sizeof(t_cylindner));
    new_element = ft_lstnew(new_cylindner);
    new_element->diffuse = DIFFUSE;
    new_element->specular = SPECULAR;
    new_element->reflective = REFLECTIVENES;
	if (count_elements(str) != 6)
	{
        if (count_elements(str) == 9)
        {
            if (set_DSR(new_element, str, 6) == FAILURE)
                return (FAILURE);
        }
        else
            return (ft_printf("Wrong number of elements in cylindner, there are %d elements in side\n", 1, count_elements(str)), FAILURE);
	}
    if (get_center(str[1], &new_cylindner->center) == FAILURE
			|| get_center(str[2], &new_cylindner->axis_direction) == FAILURE
			|| get_single_double(str[3], &new_cylindner->diameter) == FAILURE
			|| get_single_double(str[4], &new_cylindner->height) == FAILURE
			|| get_trgb(str[5], &new_cylindner->colour) == FAILURE)
	{
		printf("failure invalid input\n");
		free(new_cylindner);
		return (FAILURE);
	}
	new_element->intersection = line_cylindner;
	new_element->surface_normal = normal_cylindner;
	new_element->get_colour = get_colour_cylindner;
	ft_lstadd_back(&data->scene->cylindner_lst, new_element);
	printf("parsing cylindner ---> center: %f,%f,%f axis_direction: %f,%f,%f diameter: %f height: %f colour: %d\n", new_cylindner->center.x, new_cylindner->center.y, new_cylindner->center.z, new_cylindner->axis_direction.x,
		   new_cylindner->center.y, new_cylindner->center.z, new_cylindner->diameter, new_cylindner->height, new_cylindner->colour);
	return (SUCCESS);
}

int interpret_triangle(char **str, t_data *data)
{
	t_list *new_element;
	t_triangle *new_triangle;

	new_triangle = malloc(sizeof(t_triangle));
    new_element = ft_lstnew(new_triangle);
    new_element->diffuse = DIFFUSE;
    new_element->specular = SPECULAR;
    new_element->reflective = REFLECTIVENES;
	if (count_elements(str) != 5)
	{
        if (count_elements(str) == 8)
        {
            if (set_DSR(new_element, str, 6) == FAILURE)
                return (FAILURE);
        }
        else
		    return (ft_printf("Wrong number of elements in cylindner, there are %d elements in side\n", 1, count_elements(str)), FAILURE);
	}
    if (get_center(str[1], &new_triangle->A) == FAILURE
        || get_center(str[2], &new_triangle->B) == FAILURE
        || get_center(str[3], &new_triangle->C) == FAILURE
        || get_trgb(str[4], &new_triangle->colour) == FAILURE)
			return (free(new_triangle), FAILURE);
	new_element->intersection = intersection_line_triangle;
	new_element->surface_normal = normal_triangle;
	new_element->get_colour = get_colour_triangle;
	ft_lstadd_back(&data->scene->triangle_lst, new_element);
	printf("parsing triangle ---> A %f,%f,%f B: %f,%f,%f C: %f,%f,%f colour: %d\n", new_triangle->A.x, new_triangle->A.y, new_triangle->A.z, new_triangle->B.x,
		   new_triangle->B.y, new_triangle->B.z, new_triangle->C.x, new_triangle->C.y, new_triangle->C.z, new_triangle->colour);
	return (SUCCESS);
}

static int set_DSR(t_list *obj, char **str, int i)
{
    if (check_doubleString(str[i]) == FAILURE
        || check_doubleString(str[i + 1]) == FAILURE
        || check_doubleString(str[i + 2]) == FAILURE)
        return (FAILURE);
    obj->diffuse = ft_atod(str[i]);
    obj->specular = ft_atod(str[i + 1]);
    obj->reflective = ft_atod(str[i + 2]);
    return (SUCCESS);
}

//cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255

//sp 0,0,20 20 255,0,0

//pl 0,0,0 0,1.0,0 255,0,225

//A 0.2 255,255,255

//C -50,0,20 0,0,0 70

// -40.0,50.0,0.0 	0.6 	10,0,255
