/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:23:24 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/14 17:13:29 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_calloc() function contiguously allocates enough space for 'count'
// objects that are 'size' bytes of memory each and returns a pointer to the
// allocated memory.  The allocated memory is filled with bytes of value zero.

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}
