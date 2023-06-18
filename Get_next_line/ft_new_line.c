/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:58:22 by estruckm          #+#    #+#             */
/*   Updated: 2023/02/25 18:58:44 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*new_line(char *storage)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr_gnl(storage, '\n');
	len = (ptr - storage) + 1;
	line = ft_substr_gnl(storage, 0, len);
	if (line == 0)
		return (NULL);
	return (line);
}
