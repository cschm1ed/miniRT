/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:57:51 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/14 17:13:37 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_strrchr() function returns a pointer to the last occurence of 
// character 'c' in the string 's'.

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;
	char			*str;

	i = ft_strlen(s);
	uc = (unsigned char)c;
	str = (char *)s;
	while (i >= 0)
	{
		if (str[i] == uc)
			return (str + i);
		i --;
	}
	return (NULL);
}
