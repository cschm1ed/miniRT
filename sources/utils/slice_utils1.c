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

	if (check_centerstring(str) == FAILURE)
		return (FAILURE);
	split = ft_split(str, ",");
	center->x = ft_atod(split[0]);
	center->y = ft_atod(split[1]);
	center->z = ft_atod(split[2]);
	free_stringarray(split);
	return (SUCCESS);
}

int	get_trgb(char *str, int *colour)
{
	char	**split;
	int		r;
	int		g;
	int		b;
	int		t;

	if (check_rgbstring(str) == FAILURE)
		return (FAILURE);
	split = ft_split(str, ",");
	t = 0;
	r = ft_atoi((const char *) split[0]);
	g = ft_atoi((const char *) split[1]);
	b = ft_atoi((const char *) split[2]);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		return (free_stringarray(split), FAILURE);
	(*colour) = get_colour(t, r, g, b);
	free_stringarray(split);
	return (SUCCESS);
}
