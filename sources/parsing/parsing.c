/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:54:41 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/18 19:54:35 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	slicer(char *str, t_data *data)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(str, ' ');
	if (split == NULL)
		return (FAILURE);
	while (i < 6)
	{
		if (!ft_strcmp(data->parsing[i].name, split[0]))
			if (data->parsing[i].f(split, data) == FAILURE)
				return (FAILURE);
		i++;
	}
	return (SUCCESS);
}


int	parsing(t_data *data)
{
	int	fd;
	char *str;


	fd = open(data->scene_filename, O_RDONLY);
	if (fd == -1)
		return (perror("open"), FAILURE);
	str = get_next_line(fd);
	while (str != NULL)
	{
		if (*str != '\n')
			if (slicer(str, data) == FAILURE)
			{
				return (FAILURE);
			}
		free(str);
		str = (get_next_line(fd));
		if (str == NULL)
			perror("malloc failure");
	}
	close(fd);
	data->scene->all_objs = data->scene->sphere_lst;
	ft_lstadd_back(&data->scene->all_objs, data->scene->plane_lst);
	return (SUCCESS);
}
