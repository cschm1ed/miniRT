/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:54:41 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/18 17:23:25 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>


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
		if (slicer(str) == FAILURE)
			return (FAILURE);
		free(str);
		str = (get_next_line(fd));
		if (str == NULL)
			perror("malloc failure")
	}
	close(fd);
}
