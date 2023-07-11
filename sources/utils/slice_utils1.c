/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slice_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:11:55 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/18 21:57:45 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int get_single_integer(char *str, int *variable)
{
	if (check_integerString(str) == FAILURE)
		return (FAILURE);
	(*variable) = ft_atoi(str);
	return (SUCCESS);
}

int get_single_double(char *str, double *variable)
{
	if (check_doubleString(str) == FAILURE)
		return (FAILURE);
	(*variable) = ft_atod((const char*)str);
	return (SUCCESS);
}

int get_center(char *str, t_vector *center)
{
	char **split;

	if (check_centerString(str) == FAILURE)
		return (FAILURE);
	split = ft_split(str, ",");
	center->x = ft_atod((const char *) split[0]);
	center->y = ft_atod((const char *) split[1]);
	center->z = ft_atod((const char *) split[2]);
	free_stringArray(split);
	return (SUCCESS);
}

int get_trgb(char *str, int *colour)
{
	char **split;
	int r;
	int g;
	int b;
	int t;

	if (check_rgbString(str) == FAILURE)
		return (FAILURE);
	split = ft_split(str, ",");
	t = 0;
	r = ft_atoi((const char *) split[0]);
	g = ft_atoi((const char *) split[1]);
	b = ft_atoi((const char *) split[2]);
	(*colour) = trgb(t, r, g, b);
	free_stringArray(split);
	return (SUCCESS);
}

int count_elements(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

long double    ft_atod(const char *str)
{
	long double    result;
	long double    double_part;

	result = ft_atoi(str);
	while (*str != '.' && *str != ',' && *str != '\0')
		str++;
	double_part = ft_atoi(str + 1);
	while (double_part > 1)
		double_part /= 10;
	return (result + double_part);
}

void free_stringArray(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
}
