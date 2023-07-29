/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:58:35 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/22 10:54:14 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

/**
 * gnl_strjoin - concatenates two strings
 * @dst: the destination string
 * @src: the source string to append
 * 
 * Allocates memory and creates a new
 * string which is the concatenation of 'dst' and 'src'.
 * The memory of the input strings is freed.
 * The memory of the new string must be freed by the caller.
 * 
 * Return: a pointer to the newly concatenated
 * string, or NULL if memory allocation failed
 */

char	*gnl_strjoin(char *dst, char *src)
{
	char	*out;
	int		i;
	int		j;

	i = 0;
	j = -1;
	out = malloc(sizeof(char) * (ft_strlen(src) + ft_strlen(dst) + 1));
	if (!out)
		return (free(src), free(dst), NULL);
	if (dst)
	{
		while (dst[i])
		{
			out[i] = dst[i];
			i ++;
		}
	}
	while (j++, src[j])
		out[i + j] = src[j];
	out[i + j] = 0;
	return (free(dst), free(src), out);
}
