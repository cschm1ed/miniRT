/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:24:46 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/14 17:20:38 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ft_strlcpy() copies at most 'dstsize' - strlen(dst) - 1 characters from 
// string 'src' to string 'dst' while guaranteeing NUL-termination.

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i ++;
	}
	((char *)dst)[i] = 0;
	return (ft_strlen(src));
}
