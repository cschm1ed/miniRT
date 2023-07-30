/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 02:02:19 by estruckm          #+#    #+#             */
/*   Updated: 2023/07/20 13:36:04 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	check_centerstring(char *str)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(str, ",");
	if (split[3] != NULL)
		return (free_stringarray(split), FAILURE);
	while (split[i] != NULL)
	{
		if (double_checker(split[i]) == FAILURE)
			return (free_stringarray(split), FAILURE);
		i++;
	}
	free_stringarray(split);
	return (SUCCESS);
}

int	check_rgbstring(char *str)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	split = ft_split(str, ",");
	if (count_elements(split) != 3)
	{
		ft_printf("wrong number arguments in colour\n");
		return (FAILURE);
	}
	while (split[i] != NULL)
	{
		j = 0;
		while (split[i][j] != '\0' && split[i][j] != '\n')
		{
			if (ft_isdigit(split[i][j]) == 0)
				return (free_stringarray(split), FAILURE);
			j++;
		}
		i++;
	}
	free_stringarray(split);
	return (SUCCESS);
}

int	double_checker(char *str)
{
	int	len;
	int	i;
	int	point_check;

	i = 0;
	point_check = 0;
	len = ft_strlen(str);
	if (str[0] == '-' || str[i] == '+')
		i++;
	if (str[0] == '.')
		return (FAILURE);
	if (str[len - 1] == '.')
		return (FAILURE);
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (ft_isdigit(str[i]) == 0 && str[i] != '.')
			return (FAILURE);
		if (str[i] == '.')
			point_check++;
		if (point_check > 1)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
