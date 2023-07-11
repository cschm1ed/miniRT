/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:52:13 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/14 17:13:36 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_strmapi() function returns a string resulting of the successive 
// application of function 'f' to every character of string 's'.

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*ptr;
	unsigned int		i;
	int					len_s;

	i = 0;
	len_s = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * len_s + 1);
	if (!ptr)
		return (NULL);
	ptr[len_s] = 0;
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		i ++;
	}
	return (ptr);
}
