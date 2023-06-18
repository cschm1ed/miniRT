/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft-clean_storage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:57:31 by estruckm          #+#    #+#             */
/*   Updated: 2023/02/25 18:57:42 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*clean_storage(char *storage)
{
	char	*new_storage;
	char	*ptr;
	int		len;

	ptr = ft_strchr_gnl(storage, '\n');
	if (ptr == NULL)
	{
		new_storage = NULL;
		return (ft_free(&storage));
	}
	else
		len = (ptr - storage) + 1;
	if (storage[len] == 0)
		return (ft_free(&storage));
	new_storage = ft_substr_gnl(storage, len, ft_strlen_gnl(storage) - len);
	ft_free(&storage);
	if (new_storage == 0)
		return (NULL);
	return (new_storage);
}
