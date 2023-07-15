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

	split = ft_split(str, " ");
	printf("string_test str = %s \n", str);
	if (split == NULL)
		return (FAILURE);
	while (i < 7)
	{
		if (!ft_strcmp(data->parsing[i].name, split[0]))
		{
			printf("iteration check\n");
			if (data->parsing[i].f(split, data) == FAILURE)
				return (free_stringArray(split), FAILURE);
		}
		i++;
	}
	return (free_stringArray(split), SUCCESS);
}


int	parsing(t_data *data)
{
	int	fd;
	char *str;


	fd = open(data->scene_filename, O_RDONLY);
	if (fd == -1)
		return (perror("open"), FAILURE);
	str = get_next_line(fd);
	if (str == NULL)
		perror("malloc failure");
	while (str != NULL)
	{
		if (*str != '\n')
			if (slicer(str, data) == FAILURE)
				return (FAILURE);
		free(str);
		str = (get_next_line(fd));
	}
	close(fd);
	ft_lstadd_back(&data->scene->all_objs, data->scene->sphere_lst);
	ft_lstadd_back(&data->scene->all_objs, data->scene->cylindner_lst);
	ft_lstadd_back(&data->scene->all_objs, data->scene->plane_lst);
    ft_lstadd_back(&data->scene->all_objs, data->scene->triangle_lst);
	return (SUCCESS);
}
