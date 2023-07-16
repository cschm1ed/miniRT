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
	int 	check;

	i = 0;
	check = 0;

	split = ft_split(str, " ");
	if (split == NULL)
		return (FAILURE);
	while (i < 7)
	{
		if (!ft_strcmp(data->parsing[i].name, split[0]))
		{
			if (data->parsing[i].f(split, data) == FAILURE)
				return (free_stringArray(split), FAILURE);
			check++;
		}
		i++;
	}
	if (check == 0)
		return (free_stringArray(split), printf("unknown identifier found\n"), FAILURE);
	return (free_stringArray(split), SUCCESS);
}

int check_AC(char *str)
{
	static int count_C;
	static int count_A;

	count_C = 0;
	count_A = 0;

	if (!ft_strncmp(str, "C", 1))
		count_C++;
	if (count_C > 1)
		return(free(str), FAILURE);
	if (!ft_strncmp(str, "A", 1))
		count_A++;
	if (count_A > 1)
		return(free(str), FAILURE);
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
	if (str == NULL)
		perror("malloc failure");
	while (str != NULL)
	{
//		printf("check %s\n", AC_check[0]);
		if (check_AC(str) == FAILURE)
		{
			printf("hit\n");
			return (FAILURE);
		}
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
