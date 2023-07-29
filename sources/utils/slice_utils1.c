/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slice_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:11:55 by estruckm          #+#    #+#             */
/*   Updated: 2023/07/20 13:18:18 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	get_single_integer(char *str, int *variable)
{
	if (check_integerString(str) == FAILURE)
		return (FAILURE);
	(*variable) = ft_atoi(str);
	return (SUCCESS);
}

int	get_single_double(char *str, double *variable)
{
	if (double_checker(str) == FAILURE)
		return (FAILURE);
	(*variable) = ft_atod(str);
	return (SUCCESS);
}

int	get_center(char *str, t_vector *center)
{
	char	**split;

	if (check_centerString(str) == FAILURE)
		return (FAILURE);
	split = ft_split(str, ",");
	center->x = ft_atod(split[0]);
	center->y = ft_atod(split[1]);
	center->z = ft_atod(split[2]);
	free_stringArray(split);
	return (SUCCESS);
}

int	get_trgb(char *str, int *colour)
{
	char	**split;
	int		r;
	int		g;
	int		b;
	int		t;

	if (check_rgbString(str) == FAILURE)
		return (FAILURE);
	split = ft_split(str, ",");
	t = 0;
	r = ft_atoi((const char *) split[0]);
	g = ft_atoi((const char *) split[1]);
	b = ft_atoi((const char *) split[2]);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		return (free_stringArray(split), FAILURE);
	(*colour) = get_colour(t, r, g, b);
	free_stringArray(split);
	return (SUCCESS);
}

int	count_elements(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

double	ft_atod(const char *str)
{
	double	result;
	int		sign;
	double	decimal_place;

	result = 0;
	sign = 1;
	decimal_place = 0.1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (ft_isdigit(*str))
		{
			result += (*str - '0') * decimal_place;
			decimal_place *= 0.1;
			str++;
		}
	}

	return (sign * result);
}

void	free_stringArray(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
