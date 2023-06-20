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

int float_checker(char *str)
{
	int len;
	int i;
	int point_check

	i = 0;
	point_check = 0;
	len = ft_strlen(str);
	if (str[0] == '.')
		return (1);
	if (str[len - 1] == '.')
		return (1);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) != 1 && str[i] != '.')
			return (1);
		if (str[i] == '.')
			point_check++;
		if (point_check > 1)
			return (1);
		i++;
	}
	return (0);
}
long double    ft_atod(const char *str)
{
	long double    result;
	long double    float_part;
	if (float_checker(str) != 0)
		printf("not a valid float variable\n");
	result = ft_atoi(str);
	while (*str != '.' && *str != ',' && *str != '\0')
		str++;
	float_part = ft_atoi(str + 1);
	while (float_part >= 1)
		float_part /= 10;
	return (result + float_part);
}

.9879.
