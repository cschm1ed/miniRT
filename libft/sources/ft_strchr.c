/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:39:14 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/14 17:13:34 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_strchr() function returns a pointer to the first occurence of 
// character 'c' in string 's'.

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;
	char			*str;

	i = 0;
	uc = (unsigned char)c;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == (unsigned char)uc)
			return ((char *)str + i);
		i ++;
	}
	if (uc == '\0')
		return ((char *)s + i);
	return (NULL);
}
