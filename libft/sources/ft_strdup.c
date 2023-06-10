/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:32:49 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/14 17:13:34 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_strdup() function allocates sufficient memory for a copy of the 
// string s1, does the copy, and returns a pointer to it.

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;

	ptr = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, ft_strlen(s1));
	ptr[ft_strlen(s1)] = 0;
	return (ptr);
}
