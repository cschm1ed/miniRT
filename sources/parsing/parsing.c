/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:54:41 by estruckm          #+#    #+#             */
/*   Updated: 2023/07/27 12:50:25 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	slicer(char *str, t_data *data)
{
	char	**split;
	int		i;
	int		check;

	i = 0;
	check = 0;
	split = ft_split(str, " \t");
	if (split == NULL)
		return (FAILURE);
	while (i < 7)
	{
		if (!ft_strcmp(data->parsing[i].name, split[0]))
		{
			if (data->parsing[i].f(split, data) == FAILURE)
				return (free_stringarray(split), FAILURE);
			check++;
		}
		i++;
	}
	free_stringarray(split);
	if (check == 0)
		return (ft_printf("ERROR\nunknown identifier found\n"), FAILURE);
	return (SUCCESS);
}

int	check_ac(char *str)
{
	int	count_c;
	int	count_a;

	count_c = 0;
	count_a = 0;
	if (!ft_strncmp(str, "C", 1))
		count_c++;
	if (count_c > 1)
		return (free(str), FAILURE);
	if (!ft_strncmp(str, "A", 1))
		count_a++;
	if (count_a > 1)
		return (free(str), FAILURE);
	return (SUCCESS);
}

int	parsing(t_data *data)
{
	int		fd;
	char	*str;

	fd = open(data->scene_filename, O_RDONLY);
	if (fd == -1)
		return (perror("open"), FAILURE);
	str = get_next_line(fd);
	if (str == NULL)
		perror("malloc failure");
	while (str != NULL)
	{
		if (check_ac(str) == FAILURE)
			return (free(str), FAILURE);
		if (*str != '\n')
			if (slicer(str, data) == FAILURE)
				return (free(str), FAILURE);
		free(str);
		str = (get_next_line(fd));
	}
	if (str)
		free(str);
	close(fd);
	return (SUCCESS);
}
