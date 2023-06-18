/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:59:41 by estruckm          #+#    #+#             */
/*   Updated: 2023/02/25 18:59:51 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file(int fd, char *storage)
{
	int		rid;
	char	*buffer;

	rid = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == 0)
		return (ft_free(&storage));
	buffer[0] = '\0';
	while (rid > 0 && ft_strchr_gnl(buffer, '\n') == 0)
	{
		rid = read (fd, buffer, BUFFER_SIZE);
		if (rid > 0)
		{
			buffer[rid] = '\0';
			storage = ft_strjoin_gnl(storage, buffer);
		}
	}
	free(buffer);
	if (rid == -1)
		return (ft_free(&storage));
	return (storage);
}
