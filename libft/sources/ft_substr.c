/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:11:14 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/14 17:13:38 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_substring() function returns a copy of a substring of maximum 
// length 'len' starting  at index 'start' in string 's'.

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*str;
	int		i;

	ptr = (char *)s + start;
	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	while (ptr[i] && (size_t)i < len)
		i ++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = 0;
	while (i--, i >= 0)
	{
		str[i] = ptr[i];
	}
	return (str);
}
