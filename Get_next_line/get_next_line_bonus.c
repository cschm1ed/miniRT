/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:42:12 by gemartin          #+#    #+#             */
/*   Updated: 2023/06/18 19:41:43 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*storage[OPEN_MAX];
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((storage[fd] != 0 && ft_strchr_gnl(storage[fd], '\n') == 0)
		||storage[fd] == 0)
		storage[fd] = read_file(fd, storage[fd]);
	if (storage[fd] == 0)
		return (NULL);
	line = new_line(storage[fd]);
	if (line == 0)
		return (ft_free(&storage[fd]));
	storage[fd] = clean_storage(storage[fd]);
	return (line);
}
